#ifndef __THE_PRINCE_ACTION_FACTORY_HPP__
#define __THE_PRINCE_ACTION_FACTORY_HPP__
/*****************************************************************************
 * ACTION FACTORY API
 * Alistair Hudson
 * version 20.08.2020.0
******************************************************************************/

#include <iostream>
#include <map>

#include "action.hpp"

namespace the_prince
{

template<class PARAMS ,class BUILDER = Action* (*)(PARAMS)>
class Factory
{
public:
    Factory(){}
    Factory(Factory&) = delete;
    Factory& operator=(Factory&) = delete;
   
    void AddAction(int key, BUILDER creation_func);

    Action* CreateAction(int key, PARAMS build_params)const;

private:
    std::map<int, BUILDER>m_factory_creation;
};

template< class PARAMS, class BUILDER>
void Factory<PARAMS, BUILDER>::AddAction(int key, BUILDER creation_func)
{
    m_factory_creation[key] = creation_func;
}

template<class PARAMS ,class BUILDER>
Action* Factory<PARAMS, BUILDER>::CreateAction(int key, PARAMS build_params)const
{
    typename std::map<int, BUILDER>::const_iterator iter;
    try
    {
        iter = m_factory_creation.find(key);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return iter->second(build_params);
}

} // namespace the_prince

#endif // __THE_PRINCE_ACTION_FACTORY_HPP__