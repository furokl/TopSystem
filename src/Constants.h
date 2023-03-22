#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace cnst
{
    const short width = 120;
    const short height = 30;

    const float aspect = (float)width / height, // console window
                pixelAspect = 9.f / 19.f,       // @
                speed = 0.25f;

    namespace key
    {
        const int W = 0x57,
                  A = 0x41,
                  S = 0x53,
                  D = 0x44;
    }
}

#endif CONSTANTS_H