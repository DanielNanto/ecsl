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
//! \section Examples Example Cmake project:
//! \subsection advice_1 I: Directory layout
//! <ol type="I">
//!   <li>Project_folder
//!     <ol type="A">
//!       <li>build</li>
//!       <li>cmake</li>
//!       <li>data</li>
//!       <li>dev</li>
//!       <li>doc</li>
//!       <li>external</li>
//!         <ol type="1">
//!           <li>ecsl</li>
//!           <li>etc</li>
//!         </ol>
//!       <li>include</li>
//!       <li>src</li>
//!     </ol>
//!   </li>
//! </ol>
//! \subsection advice_2 II: Cmake functions
//! <ol type="I">
//!   <li>set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/ecsl.h)</li>
//! <li>add_subdirectory(external/ecsl)</li>
//! <li>target_link_libraries(${PROJECT_NAME} ecsl)</li>  
//!  
//! \version 0.1.0  

#include "ecsl_int.h"
#include "ecsl_str.h"
#include "ecsl_file.h"
#include "ecsl_time.h"

#endif