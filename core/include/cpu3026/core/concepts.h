#pragma once
#include <concepts>
#include <type_traits>

namespace cpu3026::concepts {
	template<typename T>
	concept memory_accessor = requires {
		typename T::address_type;
		typename T::word_type;
	};

	template<typename A, typename B>
	concept compatible_memory_accessor =
		memory_accessor<A> &&
		memory_accessor<B> &&
		std::same_as<typename A::address_type, typename B::address_type>&&
		std::same_as<typename A::word_type, typename B::word_type>;

	template<typename T>
	concept basic_processor = memory_accessor<T> &&
		requires(T p, T::address_type addr, T::word_type word, bool rw) {
		typename T::count_type;
		typename T::bit_flag;
		{ p.run_once(&addr, &word, &rw) } -> std::same_as<typename T::count_type>;
	};

	template<typename T>
	concept processor = basic_processor<T> &&
		requires(T p, T::address_type addr, T::word_type word, bool rw, T::memory_select_type mem_select) {
		typename T::memory_select_type;
		{ p.run_once(&addr, &word, &rw, &mem_select) } -> std::same_as<typename T::count_type>;
	};

	template<typename T, typename P>
	concept memory =
		processor<P> &&
		memory_accessor<T> &&
		compatible_memory_accessor<T, P>&&
		requires(T m, T::address_type addr, T::word_type word) {
			{ m.read(addr) } -> std::same_as<typename T::word_type>;
			{ m.write(addr, word) } -> std::same_as<void>;
	};
}
