#ifndef ECSL_H_
#define ECSL_H_

//! \mainpage ECSL Extended C Standard Library  
//! Title: ecsl  
//! Author(s): Daniel Nanto  
//! Company: N/A  
//! License: BSD 3-Clause License  
//! Date: 2022.8.10 (ISO 8601)  
//! Standard: JSF-AV C++ | Google C++  
//! Notes: These are some functions I use frequently enough to collect in one place  
//! \section Dependencies Non-standard dependencies:
//! N/A
//! \section Examples Example Cmake project:
//! \subsection advice_1 I: Directory layout
//! Project_folder  
//!   Software    
//!     Project_software  
//!       Build  
//!       Cmake  
//!       Data  
//!       Dev  
//!       Doc  
//!       External  
//!         Etc  
//!       Include  
//!       Src  
//! \subsection advice_2 II: Cmake
//! set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/ecsl.h)  
//! add_subdirectory(external/ecsl)  
//! target_link_libraries(${PROJECT_NAME} ecsl)  
//! \version 1.0.0  

#include "ecsl_int.h"
#include "ecsl_str.h"
#include "ecsl_file.h"
#include "ecsl_time.h"

#endif