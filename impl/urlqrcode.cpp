#include "qrlib/urlqrcode.h"
#include "qrencode.h"

namespace qrlib
{
	struct UrlQRCode::Impl
	{
		QRcode* qrcode{nullptr};
	};

	UrlQRCode::UrlQRCode(const std::string& str)
	{
		m_impl.reset(new Impl());
		m_impl->qrcode = QRcode_encodeString(str.c_str(), 2, QR_ECLEVEL_Q, QR_MODE_8, 1);
	}

	UrlQRCode::~UrlQRCode()
	{
		QRcode_free(m_impl->qrcode);
	}

	int UrlQRCode::width()
	{
		return m_impl->qrcode->width > 0 ? m_impl->qrcode->width : 1;
	}

	unsigned char UrlQRCode::pixel(int x, int y)
	{
		int w = width();
		if (x < 0 || x >= w || y < 0 || y >= w)
			return 0;

		unsigned char b = m_impl->qrcode->data[y * w + x];
		return b;
	}
}