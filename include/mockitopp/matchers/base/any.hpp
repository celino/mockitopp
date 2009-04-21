#ifndef __MOCKITOPP_MATCHER_ANY_HPP__
#define __MOCKITOPP_MATCHER_ANY_HPP__

#include <mockitopp/matchers/Matcher.hpp>

namespace mockitopp
{
   namespace matcher
   {
      namespace detail
      {
         template <typename T>
         struct AnyT : public Matcher<T>
         {
            AnyT()
               {}

            virtual Matcher<T>* clone() const
               { return new AnyT(); }

            virtual bool operator== (const T& rhs) const
               { return true; }
         };
      } // namespace detail

      template <typename T>
      detail::AnyT<T> any()
         { return detail::AnyT<T>(); }
   } // namespace matcher
} // namespace mockitopp

#endif //__MOCKITOPP_MATCHER_ANY_HPP__
