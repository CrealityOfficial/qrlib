#ifndef QRLIB_URLQRCODE_1645164546236_H
#define QRLIB_URLQRCODE_1645164546236_H
#include "qrlib/interface.h"
#include <memory>
#include <string>

namespace qrlib
{
	class UrlQRCode
	{
	public:
		UrlQRCode(const std::string& str);
		~UrlQRCode();

		int width();
		unsigned char pixel(int x, int y);

	protected:
		struct Impl;
		std::unique_ptr<Impl> m_impl;
	};
}

#endif // QRLIB_URLQRCODE_1645164546236_H