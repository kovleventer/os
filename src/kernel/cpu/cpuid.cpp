#include "cpuid.h"

namespace CPU {
	char vendor_id[12];
	uint32_t max_cpuid_param;
	
	uint8_t steppingID, model, family, processorType, extendedModel, extendedFamily, brandIndex, CLFLUSHLineSize, initialACICID;
	uint32_t extendedFeatureFlags, featureFlags;
	
	
	
	
	void update_cpuid() {
		uint32_t eax = 0, ebx, ecx, edx;
		cpuid_call(eax, ebx, ecx, edx);
		max_cpuid_param = eax;
		*((uint32_t*)&vendor_id[0]) = ebx;
		*((uint32_t*)&vendor_id[4]) = edx;
		*((uint32_t*)&vendor_id[8]) = ecx;
		
		for (uint32_t i = 1; i <= max_cpuid_param; i++) {
			eax = i;
			cpuid_call(eax, ebx, ecx, edx);
			switch (i) {
				case 1:
					steppingID = eax & LOWER_MASK;
					model = eax & HIGHER_MASK;
					family = (eax >> 8) & LOWER_MASK;
					processorType = (eax >> 8) & HIGHER_MASK; // TODO use only 2 bits
					extendedModel = (eax >> 16) & LOWER_MASK;
					extendedFamily = (eax >> 16) & HIGHER_MASK;
					
					brandIndex = ebx;
					CLFLUSHLineSize = ebx >> 8;
					initialACICID = ebx >> 24;
					
					extendedFeatureFlags = ecx;
					featureFlags = edx;
					break;
				case 2:
					break;
					
			}
		}
	}
	
	char* get_vendor_id(char* dest) {
		for (int i = 0; i < 12; i++) {
			dest[i] = vendor_id[i];
		}
		return dest;
	}
	
	uint32_t get_max_cpuid_param() {
		return max_cpuid_param;
	}
	
	uint8_t get_steppingID() {
		return steppingID;
	}
	
	uint8_t get_model() {
		return model;
	}
	
	uint8_t get_family() {
		return family;
	}
	
	uint8_t get_processorType() {
		return processorType;
	}
	
	uint8_t get_extendedModel() {
		return extendedModel;
	}
	
	uint8_t get_extendedFamily() {
		return extendedFamily;
	}
	
	uint8_t get_brandIndex() {
		return brandIndex;
	}
	
	uint8_t get_CLFLUSHLineSize() {
		return CLFLUSHLineSize;
	}
	
	uint8_t get_initialACICID() {
		return initialACICID;
	}
	
	uint32_t get_extendedFeatureFlags() {
		return extendedFeatureFlags;
	}
	
	uint32_t get_featureFlags() {
		return featureFlags;
	}
	
}

