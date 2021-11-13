//
//  SIPTune.hpp
//  CPUTune
//
//  Copyright (c) 2018 syscl. All rights reserved.
//

#ifndef SIPTune_hpp
#define SIPTune_hpp

#include <pexpert/pexpert.h>
#include "csr.h"

class SIPTune {
public:
    SIPTune();
    ~SIPTune();
    
    bool getCSRActiveConfig(uint32_t flag) const;
    void allowUntrustedKexts(void) { setBootCSRActiveConfig(CSR_ALLOW_UNTRUSTED_KEXTS); };
    void allowUnrestrictedFS(void) { setBootCSRActiveConfig(CSR_ALLOW_UNRESTRICTED_FS); };
    void allowTaskForPID(void) { setBootCSRActiveConfig(CSR_ALLOW_TASK_FOR_PID); };
    void allowUnrestrictedDtrace(void) { setBootCSRActiveConfig(CSR_ALLOW_UNRESTRICTED_DTRACE); };
    void allowUnrestrictedNVRAM(void) { setBootCSRActiveConfig(CSR_ALLOW_UNRESTRICTED_NVRAM); };
    
private:
    uint32_t *gBootCSRActiveConfig = nullptr;
    uint32_t *getBootCSRActiveConfig(void) const;
    
    // Combination usage e.g. flag = (CSR_ALLOW_UNTRUSTED_KEXTS + CSR_ALLOW_UNRESTRICTED_FS)
    void setBootCSRActiveConfig(const uint32_t flag);
};

#endif /* SIPTune_hpp */
