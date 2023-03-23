#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace cnst
{
    const short width = 120, 
                height = 30;

    const float aspect = (float)width / height, // console window
                pixelAspect = 9.f / 19.f,       // @
                speed = 0.2f,
                slow = 2.f,
                stop_range = 1.f;

    namespace key
    {
        const int W = 0x57,
                  A = 0x41,
                  S = 0x53,
                  D = 0x44;
    }
}

#endif // !CONSTANTS_H