/* auto-generated on 2025-03-08 13:17:11 -0500. Do not edit! */
/* begin file include/idna.h */
#ifndef ADA_IDNA_H
#define ADA_IDNA_H

/* begin file include/ada/idna/unicode_transcoding.h */
#ifndef ADA_IDNA_UNICODE_TRANSCODING_H
#define ADA_IDNA_UNICODE_TRANSCODING_H

#include <string>
#include <string_view>

namespace ada::idna {

size_t utf8_to_utf32(const char* buf, size_t len, char32_t* utf32_output);

size_t utf8_length_from_utf32(const char32_t* buf, size_t len);

size_t utf32_length_from_utf8(const char* buf, size_t len);

size_t utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output);

}  // namespace ada::idna

#endif  // ADA_IDNA_UNICODE_TRANSCODING_H
/* end file include/ada/idna/unicode_transcoding.h */
/* begin file include/ada/idna/mapping.h */
#ifndef ADA_IDNA_MAPPING_H
#define ADA_IDNA_MAPPING_H

#include <string>
#include <string_view>

namespace ada::idna {

// If the input is ascii, then the mapping is just -> lower case.
void ascii_map(char* input, size_t length);
// Map the characters according to IDNA, returning the empty string on error.
std::u32string map(std::u32string_view input);

}  // namespace ada::idna

#endif
/* end file include/ada/idna/mapping.h */
/* begin file include/ada/idna/normalization.h */
#ifndef ADA_IDNA_NORMALIZATION_H
#define ADA_IDNA_NORMALIZATION_H

#include <string>
#include <string_view>

namespace ada::idna {

// Normalize the characters according to IDNA (Unicode Normalization Form C).
void normalize(std::u32string& input);

}  // namespace ada::idna
#endif
/* end file include/ada/idna/normalization.h */
/* begin file include/ada/idna/punycode.h */
#ifndef ADA_IDNA_PUNYCODE_H
#define ADA_IDNA_PUNYCODE_H

#include <string>
#include <string_view>

namespace ada::idna {

bool punycode_to_utf32(std::string_view input, std::u32string& out);
bool verify_punycode(std::string_view input);
bool utf32_to_punycode(std::u32string_view input, std::string& out);

}  // namespace ada::idna

#endif  // ADA_IDNA_PUNYCODE_H
/* end file include/ada/idna/punycode.h */
/* begin file include/ada/idna/validity.h */
#ifndef ADA_IDNA_VALIDITY_H
#define ADA_IDNA_VALIDITY_H

#include <string>
#include <string_view>

namespace ada::idna {

/**
 * @see https://www.unicode.org/reports/tr46/#Validity_Criteria
 */
bool is_label_valid(std::u32string_view label);

}  // namespace ada::idna

#endif  // ADA_IDNA_VALIDITY_H
/* end file include/ada/idna/validity.h */
/* begin file include/ada/idna/to_ascii.h */
#ifndef ADA_IDNA_TO_ASCII_H
#define ADA_IDNA_TO_ASCII_H

#include <string>
#include <string_view>

namespace ada::idna {

// Converts a domain (e.g., www.google.com) possibly containing international
// characters to an ascii domain (with punycode). It will not do percent
// decoding: percent decoding should be done prior to calling this function. We
// do not remove tabs and spaces, they should have been removed prior to calling
// this function. We also do not trim control characters. We also assume that
// the input is not empty. We return "" on error.
//
//
// This function may accept or even produce invalid domains.
std::string to_ascii(std::string_view ut8_string);

// Returns true if the string contains a forbidden code point according to the
// WHATGL URL specification:
// https://url.spec.whatwg.org/#forbidden-domain-code-point
bool contains_forbidden_domain_code_point(std::string_view ascii_string);

bool constexpr is_ascii(std::u32string_view view);
bool constexpr is_ascii(std::string_view view);

}  // namespace ada::idna

#endif  // ADA_IDNA_TO_ASCII_H
/* end file include/ada/idna/to_ascii.h */
/* begin file include/ada/idna/to_unicode.h */

#ifndef ADA_IDNA_TO_UNICODE_H
#define ADA_IDNA_TO_UNICODE_H

#include <string_view>

namespace ada::idna {

std::string to_unicode(std::string_view input);

}  // namespace ada::idna

#endif  // ADA_IDNA_TO_UNICODE_H
/* end file include/ada/idna/to_unicode.h */
/* begin file include/ada/idna/identifier.h */
#ifndef ADA_IDNA_IDENTIFIER_H
#define ADA_IDNA_IDENTIFIER_H

#include <string>
#include <string_view>

namespace ada::idna {

// Verify if it is valid name code point given a Unicode code point and a
// boolean first: If first is true return the result of checking if code point
// is contained in the IdentifierStart set of code points. Otherwise return the
// result of checking if code point is contained in the IdentifierPart set of
// code points. Returns false if the input is empty or the code point is not
// valid. There is minimal Unicode error handling: the input should be valid
// UTF-8. https://urlpattern.spec.whatwg.org/#is-a-valid-name-code-point
bool valid_name_code_point(char32_t code_point, bool first);

}  // namespace ada::idna

#endif
/* end file include/ada/idna/identifier.h */

#endif
/* end file include/idna.h */
