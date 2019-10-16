#include "cpuid.h"

namespace CPU {
	char vendor_id[12];
	uint32_t max_cpuid_param;
	
	uint8_t steppingID, model, family, processorType, extendedModel, extendedFamily, brandIndex, CLFLUSHLineSize, initialACICID;
	uint32_t ecxFeatureFlags, edxFeatureFlags;
	
	// ecx feature codes
	const int SSE3_MASK = 1 << 0;
	const int PCLMULQDQ_MASK = 1 << 1;
	const int DTES64_MASK = 1 << 2;
	const int MONITOR_MASK = 1 << 3;
	const int DS_CPL_MASK = 1 << 4;
	const int VMX_MASK = 1 << 5;
	const int SMX_MASK = 1 << 6;
	const int EIST_MASK = 1 << 7;
	const int TM2_MASK = 1 << 8;
	const int SSSE3_MASK = 1 << 9;
	const int CNTX_ID_MASK = 1 << 10;
	const int SDBG_MASK = 1 << 11;
	const int FMA_MASK = 1 << 12;
	const int CMPXCHG16B_MASK = 1 << 13;
	const int XTPR_UC_MASK = 1 << 14;
	const int PDCM_MASK = 1 << 15;
	// const int _MASK = 1 << 16; reserved
	const int PCID_MASK = 1 << 17;
	const int DCA_MASK = 1 << 18;
	const int SSE4_1_MASK = 1 << 19;
	const int SSE4_2_MASK = 1 << 20;
	const int X2APIC_MASK = 1 << 21;
	const int MOVBE_MASK = 1 << 22;
	const int POPCNT_MASK = 1 << 23;
	const int TSC_DEADLINE_MASK = 1 << 24;
	const int AESNI_MASK = 1 << 25;
	const int XSAVE_MASK = 1 << 26;
	const int OSXSAVE_MASK = 1 << 27;
	const int AVX_MASK = 1 << 28;
	const int F16C_MASK = 1 << 29;
	const int RDRAND_MASK = 1 << 30;
	// const int _MASK = 31; reserved
	
	// edx feature codes
	const int FPU_MASK = 1 << 0;
	const int VME_MASK = 1 << 1;
	const int DE_MASK = 1 << 2;
	const int PSE_MASK = 1 << 3;
	const int TSC_MASK = 1 << 4;
	const int MSR_MASK = 1 << 5;
	const int PAE_MASK = 1 << 6;
	const int MCE_MASK = 1 << 7;
	const int CX8_MASK = 1 << 8;
	const int APIC_MASK = 1 << 9;
	// const int _MASK = 1 << 10; reserved
	const int SEP_MASK = 1 << 11;
	const int MTRR_MASK = 1 << 12;
	const int PGE_MASK = 1 << 13;
	const int MCA_MASK = 1 << 14;
	const int CMOV_MASK = 1 << 15;
	const int PAT_MASK = 1 << 16;
	const int PSE36_MASK = 1 << 17;
	const int PSN_MASK = 1 << 18;
	const int CLFSH_MASK = 1 << 19;
	// const int _MASK = 1 << 20; reserved
	const int DS_MASK = 1 << 21;
	const int ACPI_MASK = 1 << 22;
	const int MMX_MASK = 1 << 23;
	const int FXSR_MASK = 1 << 24;
	const int SSE_MASK = 1 << 25;
	const int SSE2_MASK = 1 << 26;
	const int SS_MASK = 1 << 27;
	const int HTT_MASK = 1 << 28;
	const int TM_MASK = 1 << 29;
	// const int _MASK = 1 << 30; reserved
	const int PBE_MASK = 1 << 31;
	
	
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
					
					ecxFeatureFlags = ecx;
					edxFeatureFlags = edx;
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
	
	uint32_t get_ecxFeatureFlags() {
		return ecxFeatureFlags;
	}
	
	uint32_t get_edxFeatureFlags() {
		return edxFeatureFlags;
	}
	
	bool ext_SSE3() {
		return SSE3_MASK & ecxFeatureFlags;
	}
	
	bool ext_PCLMULQDQ() {
		return PCLMULQDQ_MASK & ecxFeatureFlags;
	}
	
	bool ext_DTES64() {
		return DTES64_MASK & ecxFeatureFlags;
	}
	
	bool ext_MONITOR() {
		return MONITOR_MASK & ecxFeatureFlags;
	}
	
	bool ext_VMX() {
		return VMX_MASK & ecxFeatureFlags;
	}
	
	bool ext_RDRAND() {
		return RDRAND_MASK & ecxFeatureFlags;
	}
	
	bool ext_FPU() {
		return FPU_MASK & edxFeatureFlags;
	}
}

