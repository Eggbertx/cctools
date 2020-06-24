/******************************************************************************
 * This file is part of CCTools.                                              *
 *                                                                            *
 * CCTools is free software: you can redistribute it and/or modify            *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * CCTools is distributed in the hope that it will be useful,                 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with CCTools.  If not, see <http://www.gnu.org/licenses/>.           *
 ******************************************************************************/

#include <QtGlobal>

// Simplified backport of QOverload
#if (QT_VERSION < QT_VERSION_CHECK(5, 7, 0))
template <typename... Args>
struct QOverload {
    template <typename R, typename T>
    static Q_DECL_CONSTEXPR auto of(R(T::*ptr)(Args...)) Q_DECL_NOTHROW -> decltype(ptr)
    {
        return ptr;
    }
};
#endif
