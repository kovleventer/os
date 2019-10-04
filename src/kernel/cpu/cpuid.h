#pragma once

#include <stdint.h>

namespace CPU {
	const uint8_t LOWER_MASK = 0x0F;
	const uint8_t HIGHER_MASK = 0xF0;
	
	inline void cpuid_call(uint32_t& eax, uint32_t& ebx, uint32_t& ecx, uint32_t& edx) {
		asm volatile (
			"cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (eax)
		);
	}
	
	void update_cpuid();
	
	char* get_vendor_id(char* dest);
	uint32_t get_max_cpuid_param();
	
	uint8_t get_steppingID();
	uint8_t get_model();
	uint8_t get_family();
	uint8_t get_processorType();
	uint8_t get_extendedModel();
	uint8_t get_extendedFamily();
	uint8_t get_brandIndex();
	uint8_t get_CLFLUSHLineSize();
	uint8_t get_initialACICID();
	uint32_t get_extendedFeatureFlags();
	uint32_t get_featureFlags();
}
