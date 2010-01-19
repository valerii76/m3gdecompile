# vim:set ts=8 sts=8 sw=8 noet:
add_library(zlib
	adler32.c
	compress.c
	crc32.c
	deflate.c
	inffast.c
	inflate.c
	inftrees.c
	trees.c
	uncompr.c
	zutil.c
)
