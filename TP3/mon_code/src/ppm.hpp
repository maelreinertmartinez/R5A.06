#ifndef PPM_HPP
#define PPM_HPP
#include <string>
#include <iostream>
#include "couleurRVB.hpp"

class PPM
{
private:
    std::string mMagic, mFilepath;
    int mH, mW, mMax;
    uint8_t * mBuffer = nullptr;
public:
    // Constructors
    // Default constructor
    PPM() = default;
    // Create PPM instance from image file
    PPM(const std::string & filepath);
    // Create PPM instance from data
    PPM(const uint8_t * buffer, const int h, const int w, const int max, const std::string magic);
    // Copy constructor
    // Create PPM instance from another PPM instance
    PPM(const PPM & ppm);
    // Destructors
    ~PPM();
    // Assign operator
    // Assign one PPM instance to another
    PPM & operator = (const PPM & ppm);
    // Equal operator
    // Check if two PPM instances are equivalent
    bool operator == (const PPM & ppm) const;
    // Read PPM from file
    int read(const std::string & filepath);
    // Save PPM to file
    int write(const std::string & filepath) const;
    // Load array as PPM
    void load(const uint8_t * buffer, const int h, const int w, const int max, const std::string magic);
    // Get attributes
    std::string getMagic() const;
    std::string getFilepath() const;
    int Hauteur() const;
    int Largeur() const;
    int getMax() const;

    RVB MapRVB(int x, int y) const {
        int pixeloffset = y * mW + x ;
        int componentoffset = pixeloffset * 3;
		RVB col;
        //std::cout<<componentoffset<<std::endl;
        col.R(mBuffer[componentoffset]/255.0);
        col.V(mBuffer[componentoffset+1]/255.0);
        col.B(mBuffer[componentoffset+2]/255.0);
		return col;
	} 
    
    uint8_t * getImageHandler() const;
    // Set magic to P3 (false) or P6 (true)
    void setBinary(const bool isBinary);

};


#endif