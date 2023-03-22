#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Shape.h"
#include "Vector2D.h"
#include <thread>
#include <mutex>
// -----------------------------------------
//              *Controller*
// 
//    W
//  A S D      
// 
// -----------------------------------------

class Controller
{
public:
    enum MoveKey
    {
        W,
        A,
        S,
        D,
        MAX_MOVEKEY
    };

    struct vecth
    {
        const int key;
        Vector2D v;
    };

private:
    Shape* actor;
    Vector2D m_v;
    std::array<std::thread, MAX_MOVEKEY> th;

    std::array<vecth, MAX_MOVEKEY> vecth_arr = { {
            { cnst::key::W, Vector2D(0.f, -cnst::speed) },
            { cnst::key::A, Vector2D(-cnst::speed, 0.f) },
            { cnst::key::S, Vector2D(0.f, cnst::speed) },
            { cnst::key::D, Vector2D(cnst::speed, 0.f) }
    } };


public:
    Controller(Shape *shape)
        : m_v(Vector2D()),
          actor(shape)
    {
        initMoveThreads();
    }

private:
    void initMoveThreads() {
        for (int i{}; i < MAX_MOVEKEY; ++i)
        {
            th[i] = std::thread([i, this]() {
                while (true)
                {
                    if (GetAsyncKeyState(vecth_arr[i].key) != 0)
                    {
                        m_v += vecth_arr[i].v;
                        actor->set_pos(actor->get_pos().moveByVector(m_v));
                        Sleep(10);
                    }
                }
            });
            th[i].detach();
        }
    }
};

#endif CONTROLLER_H