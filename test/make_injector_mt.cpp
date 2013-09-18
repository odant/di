//
// Copyright (c) 2012-2013 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "boost/di/concepts.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>

#include "boost/di/concepts.hpp"
#include "boost/di/make_injector.hpp"

#include "data.hpp"

namespace boost {
namespace di {

BOOST_AUTO_TEST_CASE(ctor) {
    using injector_c0 = injector<
        c0if0
    >;

    shared_ptr<c5> c5_ = injector_c0().create<shared_ptr<c5>>();
    BOOST_CHECK_EQUAL(0, c5_->c2_->i);
}

BOOST_AUTO_TEST_CASE(empty) {
    auto injector_empty = make_injector();
    BOOST_CHECK_EQUAL(0, injector_empty.create<c3>().i);
}

BOOST_AUTO_TEST_CASE(by_value) {
    using injector_c0 = injector<
        c0if0
    >;

    auto injector_c0_int_ = make_injector(
        injector_c0()
      , bind<int>::to(42)
    );

    shared_ptr<c5> c5_ = injector_c0_int_.create<shared_ptr<c5>>();
    BOOST_CHECK_EQUAL(42, c5_->c2_->i);
}

BOOST_AUTO_TEST_CASE(factory) {
    auto injector_ = make_injector(
        bind<if0, if0_factory>()
      , bind<eid>::to(e0)
    );

    BOOST_CHECK(dynamic_cast<c0if0*>(injector_.create<c23>().if0_.get()));
}

} // namespace di
} // namespace boost

