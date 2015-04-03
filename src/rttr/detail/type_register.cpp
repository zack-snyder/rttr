/************************************************************************************
*                                                                                   *
*   Copyright (c) 2014, 2015 Axel Menzel <info@axelmenzel.de>                       *
*                                                                                   *
*   This file is part of RTTR (Run Time Type Reflection)                            *
*   License: MIT License                                                            *
*                                                                                   *
*   Permission is hereby granted, free of charge, to any person obtaining           *
*   a copy of this software and associated documentation files (the "Software"),    *
*   to deal in the Software without restriction, including without limitation       *
*   the rights to use, copy, modify, merge, publish, distribute, sublicense,        *
*   and/or sell copies of the Software, and to permit persons to whom the           *
*   Software is furnished to do so, subject to the following conditions:            *
*                                                                                   *
*   The above copyright notice and this permission notice shall be included in      *
*   all copies or substantial portions of the Software.                             *
*                                                                                   *
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
*   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
*   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
*   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
*   SOFTWARE.                                                                       *
*                                                                                   *
*************************************************************************************/

#include "rttr/detail/type_register.h"
#include "rttr/detail/type_database_p.h"

#include "rttr/detail/constructor_container_base.h"
#include "rttr/detail/destructor_container_base.h"
#include "rttr/detail/enumeration_container_base.h"
#include "rttr/detail/method_container_base.h"
#include "rttr/detail/property_container.h"
#include "rttr/detail/array_container_base.h"

using namespace std;

namespace rttr
{
namespace detail
{

/////////////////////////////////////////////////////////////////////////////////////////

void type_register::property(const type& t, unique_ptr<property_container_base> prop)
{
   type_database::instance().register_property(t, move(prop));
}

/////////////////////////////////////////////////////////////////////////////////////////

void type_register::method(const type& t, std::unique_ptr<detail::method_container_base> method)
{
    type_database::instance().register_method(t, move(method));
}

/////////////////////////////////////////////////////////////////////////////////////////

void type_register::constructor(const type& t, std::unique_ptr<detail::constructor_container_base> ctor)
{
    type_database::instance().register_constructor(t, move(ctor));
}

/////////////////////////////////////////////////////////////////////////////////////////

void type_register::destructor(const type& t, std::unique_ptr<detail::destructor_container_base> dtor)
{
    type_database::instance().register_destructor(t, move(dtor));
}

/////////////////////////////////////////////////////////////////////////////////////////

void type_register::enumeration(const type& t, std::unique_ptr<detail::enumeration_container_base> enum_item)
{
    type_database::instance().register_enumeration(t, move(enum_item));
}

/////////////////////////////////////////////////////////////////////////////////////////

void type_register::custom_name(const type& t, std::string custom_name)
{
    type_database::instance().register_custom_name(t, move(custom_name));
}

/////////////////////////////////////////////////////////////////////////////////////////

void type_register::metadata(const type& t, std::vector< rttr::metadata > metadata)
{
    type_database::instance().register_metadata(t, move(metadata));
}

/////////////////////////////////////////////////////////////////////////////////////////

void type_register::converter(const type& t, std::unique_ptr<detail::type_converter_base> converter)
{
     type_database::instance().register_converter(t, move(converter));
}

/////////////////////////////////////////////////////////////////////////////////////////

uint16 type_register::type_reg(const char* name, 
                               const type& raw_type,
                               const type& array_raw_type,
                               vector<base_class_info> base_classes,
                               get_derived_func derived_func_ptr,
                               variant_create_func var_func_ptr,
                               bool is_class,
                               bool is_enum,
                               bool is_array,
                               bool is_pointer,
                               bool is_primitive,
                               bool is_function_pointer,
                               bool is_member_object_pointer,
                               bool is_member_function_pointer,
                               std::size_t pointer_dimension)
{
    return type_database::instance().register_type(name, raw_type, array_raw_type, move(base_classes), 
                                                   derived_func_ptr, var_func_ptr, is_class, is_enum, 
                                                   is_array, is_pointer, is_primitive, is_function_pointer, 
                                                   is_member_object_pointer, is_member_function_pointer, pointer_dimension);
}

/////////////////////////////////////////////////////////////////////////////////////////

} // end namespace detail
} // end