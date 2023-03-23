#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <thread>

#include "Shape.h"
#include "Vector2D.h"

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
    Shape* m_actor;
    Vector2D m_v;
    bool m_th_work = true;

    std::thread m_th_stop;
    std::thread m_th_setPos;
    std::array<std::thread, MAX_MOVEKEY> m_th_key;
    std::array<vecth, MAX_MOVEKEY> vecth_arr = { {
            { cnst::key::W, Vector2D(0.f, -cnst::speed) },
            { cnst::key::A, Vector2D(-cnst::speed, 0.f) },
            { cnst::key::S, Vector2D(0.f, cnst::speed) },
            { cnst::key::D, Vector2D(cnst::speed, 0.f) }
    } };

public:
    Controller(Shape* shape)
        : m_v(Vector2D()),
          m_actor(shape)
    {
        initMoveThreads();
        initReverseMoveThread();
        initSetPositionThread();
    }
    ~Controller()
    {
        m_th_work = false;
    }

    Controller(const Controller &controller) = delete;
    Controller &operator=(const Controller &controller) = delete;
    Controller(Controller &&controller) noexcept;
    Controller &operator=(Controller &&controller) noexcept;

    void operator=(Shape *shape);

    void initMoveThreads();
    void initReverseMoveThread();
    void initSetPositionThread();
};

#endif // !CONTROLLER_H