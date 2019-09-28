#ifndef QRCode_TOOL_H
#define QRCode_TOOL_H
#include <string>
namespace qrcode{
	namespace tool{
		/**
		 *
		 * @param <code>std::string</code> object
		 * 
		 * @return <code>true</code> if the object is
		 * pure digital,otherwise return <code>false</code> 
		 *
		 */
		bool is_pure_digital(const std::string & src);
		/**
		 *
		 * @param <code>std::string &</code> source
		 *
		 * @return the code converted from number mode
		 */
		std::string number_mode_encoding(const std::string & src);
		/**
		 *
		 * @param <code>std::string</code> source
		 *
		 * @return <code>std::string</code> object
		 *  converted from decimal to binary 
		 * 
		 * 
		 */
		std::string decimal_to_binary(int src);
	}
	
};
#endif