//
// Copyright (c) 2012 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#if !BOOST_PP_IS_ITERATING

    #ifndef BOOST_DI_FUSION_MODULE_HPP
    #define BOOST_DI_FUSION_MODULE_HPP

    #include <boost/preprocessor/iteration/iterate.hpp>
    #include <boost/mpl/limits/vector.hpp>
    #include "boost/di/detail/module.hpp"
    #include "boost/di/concepts.hpp"
    #include "boost/di/config.hpp"

    #define BOOST_PP_ITERATION_PARAMS_1 (   \
        BOOST_DI_ITERATION_PARAMS(          \
            1                               \
          , BOOST_MPL_LIMIT_VECTOR_SIZE     \
          , "boost/di/fusion_module.hpp"    \
        )                                   \
    )

    namespace boost {
    namespace di {

    namespace detail {

    template<typename TDeps>
    struct fusion_dependencies
        : mpl::fold<
              TDeps
            , mpl::vector0<>
            , mpl::copy<
                  mpl::if_<
                      mpl::is_sequence<mpl::_2>
                    , mpl::_2
                    , per_request<mpl::_2>
                  >
                , mpl::back_inserter<mpl::_1>
              >
          >::type
    { };

    } // namespace detail

    template<
        typename TSequence = mpl::vector0<>
    >
    class fusion_module
        : public detail::module<
              typename detail::fusion_dependencies<TSequence>::type
            , TSequence
          >
    {
    public:
        fusion_module() { }

        #include BOOST_PP_ITERATE()

        fusion_module<> operator()() const {
            return fusion_module<>();
        }
    };

    } // namespace di
    } // namespace boost

    #endif

#else

    template<BOOST_DI_ARGS_TYPES(Args)>
    fusion_module(BOOST_DI_ARGS(Args, args))
        : detail::module<
              typename detail::fusion_dependencies<TSequence>::type
            , TSequence
          >
        (BOOST_DI_ARGS_FORWARD(args))
    { }

    template<BOOST_DI_ARGS_TYPES(Args)>
    fusion_module<mpl::vector<BOOST_DI_ARGS_PASS_TYPES(Args)> >
    operator()(BOOST_DI_ARGS(Args, args)) const {
        return fusion_module<mpl::vector<BOOST_DI_ARGS_PASS_TYPES(Args)> >(
            BOOST_DI_ARGS_FORWARD(args));
    }

#endif

