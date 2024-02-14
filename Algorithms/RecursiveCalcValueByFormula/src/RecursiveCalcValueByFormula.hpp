#pragma once

#include <concepts>



namespace __detail
{
    template <std::integral T>
    double __RecursiveCalcValueByFormula(double _curr_value, T _curr_step, T _parametr) noexcept
    {
        if (_curr_step == _parametr)
            return _curr_value;

        auto new_value = _curr_value * 3 / (_curr_step + 1);

        return __RecursiveCalcValueByFormula(new_value, _curr_step + 1, _parametr);
    }
}

/*
    Formula: 
        3^n
        ___
        n!
*/

template <std::integral T>
double RecursiveCalcValueByFormula(T _parametr) noexcept
{
    return __detail::__RecursiveCalcValueByFormula(1, 0, _parametr);
}