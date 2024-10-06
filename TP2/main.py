import os
import numpy as np
from math import sin, pi
from PIL import Image
import noise
from tqdm import tqdm
import multiprocessing

def generate_pixels(width, height, scale, octaves, i):
    pixels = np.zeros((height, width, 3), dtype=np.uint8)
    for x in range(width):
        for y in range(height):
            perlin_value = noise.pnoise2((x + 20 * i) / scale, y / scale, octaves=octaves)
            base_value = (x / width + y / height + perlin_value) * 10
            r = int((sin(base_value + i / 100) * 0.5 + 0.5) * 255)
            g = int((sin(base_value + 2 * pi / 3 + i / 100) * 0.5 + 0.5) * 255)
            b = int((sin(base_value + 4 * pi / 3 + i / 100) * 0.5 + 0.5) * 255)
            pixels[y, x] = [r, g, b]
    return pixels

def make_new_image(args):
    width, height, scale, octaves, i = args
    pixels = generate_pixels(width, height, scale, octaves, i)
    image = Image.fromarray(pixels)
    image.save(f"video/IMG_{i:03d}.png")

def main():
    width, height = 1920, 1080
    scale = 400
    octaves = 1
    num_cores = os.cpu_count() - 1

    tasks = [(width, height, scale, octaves, i) for i in range(400)]

    with multiprocessing.Pool(processes=num_cores) as pool:
        for _ in tqdm(pool.imap_unordered(make_new_image, tasks), total=len(tasks)):
            pass

if __name__ == '__main__':
    main()