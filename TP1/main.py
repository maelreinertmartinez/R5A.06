from os import cpu_count
import multiprocessing
from itertools import count
from math import floor, ceil
from random import randint
from tqdm import tqdm

from PIL import Image, ImageDraw, ImageFilter

from Star import Star

def process_frame(args):
    i, frame, width, height, max_distance, voie = args

    img = Image.new('RGBA', (width,height), (0,0,0,0))
    for star in frame:
        rayon = (max_distance - star.distance) / 125
        draw = ImageDraw.Draw(img)
        draw.ellipse((star.x - rayon, star.y - rayon, star.x + rayon, star.y + rayon), fill=(255, 255, 255, 255 - star.distance))
    img = Image.alpha_composite(voie, img)
    img.save(f"video/frame_{i:03d}.png")

if __name__ == '__main__':
    
    width = 800
    height = 600
    max_distance = 255

    nb_stars = 500

    nb_images = 400

    stars : list[list[Star]] = []
    stars.append([])
    voie = Image.open("voie_lactee.png")

    for i in range(nb_stars):
        star_distance = randint(0, max_distance)
        t = 2 * int((max_distance - star_distance) / 85)
        if t == 0:
            star_width = randint(0, width)
        else:
            star_width = randint(t, int(width/t)) * t - t
        star_height = randint(0, height - 1)
        stars[0].append(Star(star_width, star_height, star_distance))
        

    for i in range(nb_images):
        stars.append([])
        for j in range(0, nb_stars):
            stars[i + 1].append(Star(stars[i][j].x + 2 * int((max_distance - stars[i][j].distance) / 85), stars[i][j].y, stars[i][j].distance))
            stars[i + 1][j].x %= width

            if (max_distance - stars[i][j].distance) // 85 > 0:
                stars[i + 1][j].y += int((stars[i][j].x - ((width / 2) - 1)) / 100)
                stars[i + 1][j].y %= height
                

    num_cores = cpu_count() - 1
    args = [(i, stars[i], width, height, max_distance, voie) for i in range(nb_images)]
    with multiprocessing.Pool(processes=num_cores) as pool:
        for _ in tqdm(pool.imap_unordered(process_frame, args), total=len(args)):
            pass
