#include "Controller.h"

// ----------------------------------------------------------
// Transfer ownership of the controller
// ----------------------------------------------------------
Controller::Controller(Controller &&controller) noexcept
    : m_actor(controller.m_actor),
      m_v(controller.m_v)
{
    controller.m_th_work = false;
    controller.m_actor = nullptr;
};

// ----------------------------------------------------------
// Transfer ownership of the controller
// ----------------------------------------------------------
Controller& Controller::operator=(Controller &&controller) noexcept {
    if (&controller == this) return *this;

    m_actor = controller.m_actor;
    m_v = controller.m_v;

    controller.m_th_work = false;
    controller.m_actor = nullptr;
    return *this;
};

// ----------------------------------------------------------
// Μενÿεμ Shape
// ----------------------------------------------------------
void Controller::operator=(Shape* shape) { m_actor = shape; }

// ----------------------------------------------------------
// Threads for move on keys WASD
// ----------------------------------------------------------
void Controller::initMoveThreads() {
    for (int i{}; i < MAX_MOVEKEY; ++i)
    {
        m_th_key[i] = std::thread([i, this]() {
            while (m_th_work)
            {
                if (GetAsyncKeyState(vecth_arr[i].key) != 0)
                {
                    m_v += vecth_arr[i].v;
                    Sleep(100);
                }
            }
        });
        m_th_key[i].detach();
    }
}

// ----------------------------------------------------------
// Thread for simulating friction force
// ----------------------------------------------------------
void Controller::initReverseMoveThread() 
{
    m_th_stop = std::thread([this]() {
        while (m_th_work) {
            if (GetAsyncKeyState(cnst::key::W) != 0 ||
                GetAsyncKeyState(cnst::key::A) != 0 ||
                GetAsyncKeyState(cnst::key::S) != 0 ||
                GetAsyncKeyState(cnst::key::D) != 0) continue;
            if (m_v.get_x() > -cnst::stop_range && m_v.get_x() < cnst::stop_range) m_v.set_x(0.f);
            else if (m_v.get_x() != 0.f) m_v.set_x(m_v.get_x() / cnst::slow);
            if (m_v.get_y() > -cnst::stop_range && m_v.get_y() < cnst::stop_range) m_v.set_y(0.f);
            else if (m_v.get_y() != 0.f) m_v.set_y(m_v.get_y() / cnst::slow);
            Sleep(500);
        }
    });
    m_th_stop.detach();
}

// ----------------------------------------------------------
// Thread for setting Shape position
// ----------------------------------------------------------
void Controller::initSetPositionThread()
{
    m_th_setPos = std::thread([this]() {
        while (m_th_work) {
            m_actor->set_pos(m_actor->get_pos().moveByVector(m_v));
            Sleep(100);
        }
    });
    m_th_setPos.detach();
}