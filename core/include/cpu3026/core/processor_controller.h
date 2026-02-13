#pragma once 
#include <cpu3026/core/concepts.h>

namespace cpu3026 {
	template<concepts::processor P, concepts::memory<P>... M>
	class processor_controller {
	public:
		using processor_type = P;
		using memory_type = std::tuple<M...>;
		using address_type = P::address_type;
		using word_type = P::word_type;
		using memory_select_type = P::memory_select_type;
		using count_type = P::count_type;

		processor_controller(processor_type*, M*...);

		count_type total_cycles() const;
		count_type total_instructions() const;

		count_type run_once();
	};

	template<concepts::processor P, concepts::memory<P> ...M>
	inline cpu3026::processor_controller<P, M...>::processor_controller(processor_type* processor, M* ... mem_map) {
		
	}
}