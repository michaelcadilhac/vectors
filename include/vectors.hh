#pragma once

namespace vectors {
  // Vectors implementing bin() should satisfy:
  //       if u.bin () < v.bin (), then u can't dominate v.
  // or equivalently:
  //       if u dominates v, then u.bin () >= v.bin ()
  template<class T, class = void>
  struct has_bin : std::false_type {};

  template <class T>
  struct has_bin<T, std::void_t<decltype (std::declval<T> ().bin ())>> : std::true_type {};

  template <template <typename T, auto...> typename T, typename Elt>
  struct traits {
      static constexpr auto capacity_for (size_t nelts) { return nelts; }
  };
}

#include "vectors/vector_backed.hh"
#include "vectors/array_backed.hh"
#include "vectors/array_ptr_backed.hh"
#include "vectors/array_backed_sum.hh"
#include "vectors/simd_vector_backed.hh"
#include "vectors/simd_array_backed.hh"
#include "vectors/simd_array_ptr_backed.hh"
#include "vectors/simd_array_backed_sum.hh"
