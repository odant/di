//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

//[common_hpp
//<-
#ifndef COMMON_HPP
#define COMMON_HPP
//->

struct ibutton { virtual ~ibutton() = default; virtual void dummy() = 0; }; struct button : ibutton { void dummy() override { }; };
struct iwindow { virtual ~iwindow() = default; virtual void dummy() = 0; }; struct window : iwindow { void dummy() override { }; };
struct iboard { virtual ~iboard() = default; virtual void dummy() = 0; }; struct board : iboard { void dummy() override { }; };

//<-
#endif
//->

//]

