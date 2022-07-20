#ifndef INCLUDE_ICONS_H
#define INCLUDE_ICONS_H

/*
 * 1st arg = ICONS_IN_TERM
 *
 * 2nd arg = NERD ICONS
 * You can find hex codes for nerd fonts here: https://www.nerdfonts.com/cheat-sheet
 *
 * 3rd arg = EMOJIS
 * You can find a list of emoji here: https://unicode.org/Public/emoji/5.0/emoji-test.txt
 * NOTE: As some emoji are stored as two characters, all of these strings must
 * be of width 2. Therefore, right pad single-width emoji with a space.
 */
#if defined(ICONS_IN_TERM)
	#define ICON_STR(I, N, E) I
#elif defined(NERD)
	#define ICON_STR(I, N, E) N
#elif defined(EMOJI)
	#define ICON_STR(I, N, E) E
#endif

/*
 * Define a string to be printed before and after the icon
 * Adjust if the icons are not printed properly
 */
#if defined(EMOJI)
	#define ICON_SIZE 2 /* emojies take up 2 cells */
	#define ICON_PADDING_RIGHT " "
#else
	#define ICON_SIZE 1
	#define ICON_PADDING_RIGHT "  "
#endif
#define ICON_PADDING_LEFT  ""
#define ICON_PADDING_LEFT_LEN  (sizeof ICON_PADDING_LEFT  - 1)
#define ICON_PADDING_RIGHT_LEN (sizeof ICON_PADDING_RIGHT - 1)

/* ARROWS */
#define MD_ARROW_UPWARD    ICON_STR("\ue5dc", "\uf55c", "⬆")
#define MD_ARROW_FORWARD   ICON_STR("\ue5cc", "\uf553", "➡")
#define MD_ARROW_DOWNWARD  ICON_STR("\ue5df", "\uf544", "⬇")

/* GENERIC */
#define ICON_DIRECTORY     ICON_STR("\ue155", "\ue5ff", "📂")
#define ICON_FILE          ICON_STR("\ue21b", "\uf713", "📃")
#define ICON_EXEC          ICON_STR("\ue0f3", "\uf144", "⚙️ ")

/* TODO: convert them all to use ICON_STR() */
// Top level and common icons
#define ICON_ARCHIVE       "\uf53b"
#define ICON_BRIEFCASE     ICON_STR("\ue187", "\uf5d5", "💼")
#define ICON_C             ICON_STR("", "\ue61e", "🇨 ")
#define ICON_CHANGELOG     ICON_STR("\ue292", "\uf7d9", "🔺")
#define ICON_CHESS         "\uf639"
#define ICON_CLOJURE       "\ue76a"
#define ICON_CONFIGURE     ICON_STR("\ue8df", "\uf423", "🔧")
#define ICON_CPLUSPLUS     ICON_STR("\uedb8", "\ue61d", ICON_C)
#define ICON_DATABASE      "\uf6b7"
#define ICON_DESKTOP       ICON_STR("\ue1cd", "\ufcbe", "🖥️ ")
#define ICON_DOCUMENT      "\uf718"
#define ICON_DOWNLOADS     ICON_STR("\ue0f9", "\uf5d7", "📥")
#define ICON_ENCRYPT       "\uf805"
#define ICON_FSHARP        "\ue7a7"
#define ICON_GIT           ICON_STR("\ue28b", "\ue5fb", "🌱")
#define ICON_HASKELL       "\ue777"
#define ICON_HTML          "\uf72d"
#define ICON_JAVA          "\ue738"
#define ICON_JAVASCRIPT    "\uf81d"
#define ICON_LICENSE       ICON_STR("\ue2af", "\uf718", "⚖️ ")
#define ICON_LINUX         "\uf83c"
#define ICON_MAKEFILE      ICON_STR("\ue7a2", "\uf68c", "🛠 ")
#define ICON_MANUAL        ICON_STR("\ue799", "\uf5bd", "❓")
#define ICON_MUSIC         ICON_STR("\ue0e2", "\uf832", "🎧")
#define ICON_MUSICFILE     "\uf886"
#define ICON_OPTICALDISK   "\ue271"
#define ICON_PICTUREFILE   "\uf71e"
#define ICON_PICTURES      ICON_STR("\ue4fb", "\uf753", "🎨")
#define ICON_PLAYLIST      "\uf910"
#define ICON_PUBLIC        ICON_STR("\ue0fc", "\ue5ff", "👀")
#define ICON_PYTHON        "\ue235"
#define ICON_REACT         "\ue625"
#define ICON_RUBY          "\ue23e"
#define ICON_SCRIPT        "\ue795"
#define ICON_TEMPLATES     ICON_STR("\ue18f", "\ufac6", "📎")
#define ICON_TEX           "\ufb68"
#define ICON_VIDEOFILE     "\uf72a"
#define ICON_VIDEOS        ICON_STR("\ue0e9", "\uf72f", "🎞 ")
#define ICON_WORDDOC       "\uf72b"


/* Numbers */
#define ICON_EXT_1         ICON_MANUAL
#define ICON_EXT_7Z        ICON_ARCHIVE

/* A */
#define ICON_EXT_A         ICON_MANUAL
#define ICON_EXT_APK       ICON_ARCHIVE
#define ICON_EXT_ASM       ICON_FILE
#define ICON_EXT_AUP       ICON_MUSICFILE
#define ICON_EXT_AVI       ICON_VIDEOFILE

/* B */
#define ICON_EXT_BAT       ICON_SCRIPT
#define ICON_EXT_BIB       ICON_TEX
#define ICON_EXT_BIN       "\uf471"
#define ICON_EXT_BMP       ICON_PICTUREFILE
#define ICON_EXT_BZ2       ICON_ARCHIVE

/* C */
#define ICON_EXT_CAB       ICON_ARCHIVE
#define ICON_EXT_CABAL     ICON_HASKELL
#define ICON_EXT_CBR       ICON_ARCHIVE
#define ICON_EXT_CBZ       ICON_ARCHIVE
#define ICON_EXT_CLASS     ICON_JAVA
#define ICON_EXT_CLJ       ICON_CLOJURE
#define ICON_EXT_CLJC      ICON_CLOJURE
#define ICON_EXT_CLJS      ICON_CLOJURE
#define ICON_EXT_CLS       ICON_TEX
#define ICON_EXT_CMAKE     ICON_MAKEFILE
#define ICON_EXT_COFFEE    "\ue751"
#define ICON_EXT_CONF      ICON_CONFIGURE
#define ICON_EXT_CPIO      ICON_ARCHIVE
#define ICON_EXT_CSS       "\ue749"
#define ICON_EXT_CUE       ICON_PLAYLIST
#define ICON_EXT_CVS       ICON_CONFIGURE

/* D */
#define ICON_EXT_DB        ICON_DATABASE
#define ICON_EXT_DEB       "\ue77d"
#define ICON_EXT_DIFF      "\uf440"
#define ICON_EXT_DLL       ICON_SCRIPT
#define ICON_EXT_DOC       ICON_WORDDOC
#define ICON_EXT_DOCX      ICON_WORDDOC

/* E */
#define ICON_EXT_EJS       ICON_JAVASCRIPT
#define ICON_EXT_ELF       ICON_LINUX
#define ICON_EXT_EPUB      ICON_MANUAL
#define ICON_EXT_EXE       ICON_EXEC

/* F */
#define ICON_EXT_FEN       ICON_CHESS
#define ICON_EXT_FSHARP    ICON_FSHARP
#define ICON_EXT_FLAC      ICON_MUSICFILE
#define ICON_EXT_FLV       ICON_VIDEOFILE
#define ICON_EXT_FS        ICON_FSHARP
#define ICON_EXT_FSI       ICON_FSHARP
#define ICON_EXT_FSSCRIPT  ICON_FSHARP
#define ICON_EXT_FSX       ICON_FSHARP

/* G */
#define ICON_EXT_GEM       ICON_RUBY
#define ICON_EXT_GIF       ICON_PICTUREFILE
#define ICON_EXT_GO        "\ufcd1"
#define ICON_EXT_GPG       ICON_ENCRYPT
#define ICON_EXT_GZ        ICON_ARCHIVE
#define ICON_EXT_GZIP      ICON_ARCHIVE

/* H */
#define ICON_EXT_H         ICON_C
#define ICON_EXT_HH        ICON_CPLUSPLUS
#define ICON_EXT_HPP       ICON_CPLUSPLUS
#define ICON_EXT_HS        ICON_HASKELL
#define ICON_EXT_HTACCESS  ICON_CONFIGURE
#define ICON_EXT_HTPASSWD  ICON_CONFIGURE
#define ICON_EXT_HTM       ICON_HTML
#define ICON_EXT_HTML      ICON_HTML
#define ICON_EXT_HXX       ICON_CPLUSPLUS

/* I */
#define ICON_EXT_ICO       ICON_PICTUREFILE
#define ICON_EXT_IMG       ICON_OPTICALDISK
#define ICON_EXT_INI       ICON_CONFIGURE
#define ICON_EXT_ISO       ICON_OPTICALDISK

/* J */
#define ICON_EXT_JAR       ICON_JAVA
#define ICON_EXT_JAVA      ICON_JAVA
#define ICON_EXT_JL        ICON_CONFIGURE
#define ICON_EXT_JPEG      ICON_PICTUREFILE
#define ICON_EXT_JPG       ICON_PICTUREFILE
#define ICON_EXT_JS        ICON_JAVASCRIPT
#define ICON_EXT_JSON      "\ufb25"
#define ICON_EXT_JSX       ICON_REACT

/* K */

/* L */
#define ICON_EXT_LHA       ICON_ARCHIVE
#define ICON_EXT_LHS       ICON_HASKELL
#define ICON_EXT_LOG       ICON_DOCUMENT
#define ICON_EXT_LUA       "\ue620"
#define ICON_EXT_LZH       ICON_ARCHIVE
#define ICON_EXT_LZMA      ICON_ARCHIVE

/* M */
#define ICON_EXT_M4A       ICON_MUSICFILE
#define ICON_EXT_M4V       ICON_VIDEOFILE
#define ICON_EXT_M         "\ufd1c"
#define ICON_EXT_MAT       "\uf0ce"
#define ICON_EXT_MD        ICON_STR("\uea45", "\ue609", "📝")
#define ICON_EXT_MK        ICON_MAKEFILE
#define ICON_EXT_MKV       ICON_VIDEOFILE
#define ICON_EXT_MOV       ICON_VIDEOFILE
#define ICON_EXT_MP3       ICON_MUSICFILE
#define ICON_EXT_MP4       ICON_VIDEOFILE
#define ICON_EXT_MPEG      ICON_VIDEOFILE
#define ICON_EXT_MPG       ICON_VIDEOFILE
#define ICON_EXT_MSI       "\uf871"

/* N */
#define ICON_EXT_NIX       "\uf313"

/* O */
#define ICON_EXT_O         ICON_MANUAL
#define ICON_EXT_OGG       ICON_MUSICFILE
#define ICON_EXT_OPUS      ICON_MUSICFILE
#define ICON_EXT_ODOWNLOAD ICON_DOWNLOADS
#define ICON_EXT_OUT       ICON_LINUX

/* P */
#define ICON_EXT_PART      ICON_DOWNLOADS
#define ICON_EXT_PATCH     "\uf440"
#define ICON_EXT_PDF       "\uf724"
#define ICON_EXT_PGN       ICON_CHESS
#define ICON_EXT_PHP       "\ue73d"
#define ICON_EXT_PNG       ICON_PICTUREFILE
#define ICON_EXT_PPT       "\uf726"
#define ICON_EXT_PPTX      "\uf726"
#define ICON_EXT_PSB       "\ue7b8"
#define ICON_EXT_PSD       "\ue7b8"
#define ICON_EXT_PY        ICON_PYTHON
#define ICON_EXT_PYC       ICON_PYTHON
#define ICON_EXT_PYD       ICON_PYTHON
#define ICON_EXT_PYO       ICON_PYTHON

/* Q */

/* R */
#define ICON_EXT_RAR       ICON_ARCHIVE
#define ICON_EXT_RC        ICON_CONFIGURE
#define ICON_EXT_ROM       "\uf795"
#define ICON_EXT_RPM       ICON_ARCHIVE
#define ICON_EXT_RSS       "\uf96b"
#define ICON_EXT_RTF       "\uf724"
#define ICON_EXT_RB        ICON_RUBY

/* S */
#define ICON_EXT_SASS      "\ue603"
#define ICON_EXT_SCSS      "\ue603"
#define ICON_EXT_SO        ICON_MANUAL
#define ICON_EXT_SCALA     "\ue737"
#define ICON_EXT_SH        ICON_SCRIPT
#define ICON_EXT_SLIM      ICON_SCRIPT
#define ICON_EXT_SLN       "\ue70c"
#define ICON_EXT_SQL       ICON_DATABASE
#define ICON_EXT_SRT       "\uf679"
#define ICON_EXT_STY       ICON_TEX
#define ICON_EXT_SUB       "\uf679"
#define ICON_EXT_SVG       ICON_PICTUREFILE

/* T */
#define ICON_EXT_TAR       ICON_ARCHIVE
#define ICON_EXT_TEX       ICON_TEX
#define ICON_EXT_TGZ       ICON_ARCHIVE
#define ICON_EXT_TS        "\ue628"
#define ICON_EXT_TSX       ICON_REACT
#define ICON_EXT_TXT       ICON_DOCUMENT
#define ICON_EXT_TXZ       ICON_ARCHIVE

/* U */

/* V */
#define ICON_EXT_VID       ICON_VIDEOFILE
#define ICON_EXT_VIM       "\ue62b"
#define ICON_EXT_VIMRC     "\ue62b"

/* W */
#define ICON_EXT_WAV       ICON_MUSICFILE
#define ICON_EXT_WEBM      ICON_VIDEOFILE
#define ICON_EXT_WEBP      ICON_PICTUREFILE
#define ICON_EXT_WMA       ICON_VIDEOFILE
#define ICON_EXT_WMV       ICON_VIDEOFILE

/* X */
#define ICON_EXT_XBPS      ICON_ARCHIVE
#define ICON_EXT_XCF       ICON_PICTUREFILE
#define ICON_EXT_XHTML     ICON_HTML
#define ICON_EXT_XLS       "\uf71a"
#define ICON_EXT_XLSX      "\uf71a"
#define ICON_EXT_XML       ICON_HTML
#define ICON_EXT_XZ        ICON_ARCHIVE

/* Y */
#define ICON_EXT_YAML      ICON_CONFIGURE
#define ICON_EXT_YML       ICON_CONFIGURE

/* Z */
#define ICON_EXT_ZIP       ICON_ARCHIVE
#define ICON_EXT_ZSH       ICON_SCRIPT
#define ICON_EXT_ZST       ICON_ARCHIVE


/* For color names, refer to: https://www.ditig.com/256-colors-cheat-sheet */
#define COLOR_LIST \
	COLOR_X(COLOR_VIDEO,        45  /* Turquoise2 */) \
	COLOR_X(COLOR_VIDEO1,       226 /* Yellow1 */) \
	COLOR_X(COLOR_AUDIO,        220 /* Gold1 */) \
	COLOR_X(COLOR_AUDIO1,       205 /* HotPink */) \
	COLOR_X(COLOR_IMAGE,        82  /* Chartreuse2 */) \
	COLOR_X(COLOR_DOCS,         202 /* OrangeRed1 */) \
	COLOR_X(COLOR_ARCHIVE,      209 /* Salmon1 */) \
	COLOR_X(COLOR_C,            81  /* SteelBlue1 */) \
	COLOR_X(COLOR_JAVA,         32  /* DeepSkyBlue3 */) \
	COLOR_X(COLOR_JAVASCRIPT,   47  /* SpringGreen2 */) \
	COLOR_X(COLOR_REACT,        39  /* DeepSkyBlue1 */) \
	COLOR_X(COLOR_CSS,          199 /* DeepPink1 */) \
	COLOR_X(COLOR_PYTHON,       227 /* LightGoldenrod1 */) \
	COLOR_X(COLOR_LUA,          19  /* Blue3 */) \
	COLOR_X(COLOR_DOCUMENT,     15  /* White */) \
	COLOR_X(COLOR_FSHARP,       31  /* DeepSkyBlue3 */) \
	COLOR_X(COLOR_RUBY,         160 /* Red3 */) \
	COLOR_X(COLOR_SCALA,        196 /* Red1 */) \
	COLOR_X(COLOR_SHELL,        47  /* SpringGreen2 */) \
	COLOR_X(COLOR_VIM,          28  /* Green4 */) \

#define COLOR_X(N, V) N = V,
enum { COLOR_LIST };
#undef COLOR_X
#define COLOR_X(N, V) N,
static const unsigned char init_colors[] = { COLOR_LIST };
#undef COLOR_X

#ifdef ICONS_GENERATE
	struct icon_pair { const char *match; const char *icon; unsigned char color; };
#endif

static const struct icon_pair dir_icon  = {"", ICON_DIRECTORY, 0};
static const struct icon_pair file_icon = {"", ICON_FILE, 0};
static const struct icon_pair exec_icon = {"", ICON_EXEC, 0};

static const struct icon_pair icons_name[] = {
	{".git",        ICON_GIT,       0},
	{"Desktop",     ICON_DESKTOP,   0},
	{"Documents",   ICON_BRIEFCASE, 0},
	{"Downloads",   ICON_DOWNLOADS, 0},
	{"Music",       ICON_MUSIC,     0},
	{"Pictures",    ICON_PICTURES,  0},
	{"Public",      ICON_PUBLIC,    0},
	{"Templates",   ICON_TEMPLATES, 0},
	{"Videos",      ICON_VIDEOS,    0},
	{"CHANGELOG",   ICON_CHANGELOG, COLOR_DOCS},
	{"configure",   ICON_CONFIGURE, 0},
	{"License",     ICON_LICENSE,   COLOR_DOCS},
	{"Makefile",    ICON_MAKEFILE,  0},
};

#ifdef ICONS_GENERATE
/* TODO: update these all */
static const struct icon_pair icons_ext[] = {
	/* Numbers */
	{"1",          ICON_MANUAL,        COLOR_DOCS},
	/* {"7z",         ICON_EXT_7Z,        COLOR_ARCHIVE}, */

	/* A */
	/* {"a",          ICON_EXT_A,         0}, */
	/* {"apk",        ICON_EXT_APK,       COLOR_ARCHIVE}, */
	/* {"asm",        ICON_EXT_ASM,       0}, */
	/* {"aup",        ICON_EXT_AUP,       COLOR_AUDIO}, */
	/* {"avi",        ICON_EXT_AVI,       COLOR_VIDEO}, */

	/* /1* B *1/ */
	/* {"bat",        ICON_EXT_BAT,       0}, */
	/* {"bib",        ICON_EXT_BIB,       0}, */
	/* {"bin",        ICON_EXT_BIN,       0}, */
	/* {"bmp",        ICON_EXT_BMP,       COLOR_IMAGE}, */
	/* {"bz2",        ICON_EXT_BZ2,       COLOR_ARCHIVE}, */

	 /* C */
	{"c",          ICON_C,             COLOR_C},
	{"c++",        ICON_CPLUSPLUS,     COLOR_C},
	/* {"cabal",      ICON_EXT_CABAL,     COLOR_VIDEO}, */
	/* {"cab",        ICON_EXT_CAB,       COLOR_ARCHIVE}, */
	/* {"cbr",        ICON_EXT_CBR,       COLOR_ARCHIVE}, */
	/* {"cbz",        ICON_EXT_CBZ,       COLOR_ARCHIVE}, */
	{"cc",         ICON_CPLUSPLUS,        COLOR_C},
	/* {"class",      ICON_EXT_CLASS,     COLOR_JAVA}, */
	/* {"clj",        ICON_EXT_CLJ,       0}, */
	/* {"cljc",       ICON_EXT_CLJC,      0}, */
	/* {"cljs",       ICON_EXT_CLJS,      0}, */
	/* {"cls",        ICON_EXT_CLS,       0}, */
	/* {"cmake",      ICON_EXT_CMAKE,     0}, */
	/* {"coffee",     ICON_EXT_COFFEE,    0}, */
	/* {"conf",       ICON_EXT_CONF,      0}, */
	/* {"cpio",       ICON_EXT_CPIO,      COLOR_ARCHIVE}, */
	{"cpp",        ICON_CPLUSPLUS,       COLOR_C},
	/* {"css",        ICON_EXT_CSS,       COLOR_CSS}, */
	/* {"cue",        ICON_EXT_CUE,       COLOR_AUDIO}, */
	/* {"cvs",        ICON_EXT_CVS,       0}, */
	{"cxx",        ICON_CPLUSPLUS,      COLOR_C},

	/* /1* D *1/ */
	/* {"db",         ICON_EXT_DB,        0}, */
	/* {"deb",        ICON_EXT_DEB,       COLOR_ARCHIVE}, */
	/* {"diff",       ICON_EXT_DIFF,      0}, */
	/* {"dll",        ICON_EXT_DLL,       0}, */
	/* {"doc",        ICON_EXT_DOC,       COLOR_DOCUMENT}, */
	/* {"docx",       ICON_EXT_DOCX,      COLOR_DOCUMENT}, */

	/*  /1* E *1/ */
	/* {"ejs",        ICON_EXT_EJS,       COLOR_JAVASCRIPT}, */
	/* {"elf",        ICON_EXT_ELF,       0}, */
	/* {"epub",       ICON_EXT_EPUB,      COLOR_DOCS}, */
	/* {"exe",        ICON_EXT_EXE,       0}, */

	/* /1* F *1/ */
	/* {"f#",         ICON_EXT_FSHARP,    COLOR_FSHARP}, */
	/* {"fen",        ICON_EXT_FEN,       0}, */
	/* {"flac",       ICON_EXT_FLAC,      COLOR_AUDIO1}, */
	/* {"flv",        ICON_EXT_FLV,       COLOR_VIDEO}, */
	/* {"fs",         ICON_EXT_FS,        COLOR_FSHARP}, */
	/* {"fsi",        ICON_EXT_FSI,       COLOR_FSHARP}, */
	/* {"fsscript",   ICON_EXT_FSSCRIPT,  COLOR_FSHARP}, */
	/* {"fsx",        ICON_EXT_FSX,       COLOR_FSHARP}, */

	/* /1* G *1/ */
	/* {"gem",        ICON_EXT_GEM,       COLOR_RUBY}, */
	/* {"gif",        ICON_EXT_GIF,       COLOR_IMAGE}, */
	/* {"go",         ICON_EXT_GO,        0}, */
	/* {"gpg",        ICON_EXT_GPG,       COLOR_ARCHIVE}, */
	/* {"gz",         ICON_EXT_GZ,        COLOR_ARCHIVE}, */
	/* {"gzip",       ICON_EXT_GZIP,      COLOR_ARCHIVE}, */

	/* /1* H *1/ */
	/* {"h",          ICON_EXT_H,         COLOR_C}, */
	/* {"hh",         ICON_EXT_HH,        COLOR_C}, */
	/* {"hpp",        ICON_EXT_HPP,       COLOR_C}, */
	/* {"hs",         ICON_EXT_HS,        COLOR_VIM}, */
	/* {"htaccess",   ICON_EXT_HTACCESS,  0}, */
	/* {"htpasswd",   ICON_EXT_HTPASSWD,  0}, */
	/* {"htm",        ICON_EXT_HTM,       0}, */
	/* {"html",       ICON_EXT_HTML,      0}, */
	/* {"hxx",        ICON_EXT_HXX,       COLOR_C}, */

	/* /1* I *1/ */
	/* {"ico",        ICON_EXT_ICO,       COLOR_IMAGE}, */
	/* {"img",        ICON_EXT_IMG,       COLOR_ARCHIVE}, */
	/* {"ini",        ICON_EXT_INI,       0}, */
	/* {"iso",        ICON_EXT_ISO,       COLOR_ARCHIVE}, */

	/* /1* J *1/ */
	/* {"jar",        ICON_EXT_JAR,       COLOR_JAVA}, */
	/* {"java",       ICON_EXT_JAVA,      COLOR_JAVA}, */
	/* {"jl",         ICON_EXT_JL,        0}, */
	/* {"jpeg",       ICON_EXT_JPEG,      COLOR_IMAGE}, */
	/* {"jpg",        ICON_EXT_JPG,       COLOR_IMAGE}, */
	/* {"js",         ICON_EXT_JS,        COLOR_JAVASCRIPT}, */
	/* {"json",       ICON_EXT_JSON,      COLOR_JAVASCRIPT}, */
	/* {"jsx",        ICON_EXT_JSX,       COLOR_REACT}, */

	/* /1* K *1/ */

	/* /1* L *1/ */
	/* {"lha",        ICON_EXT_LHA,       COLOR_ARCHIVE}, */
	/* {"lhs",        ICON_EXT_LHS,       COLOR_VIM}, */
	/* {"log",        ICON_EXT_LOG,       0}, */
	/* {"lua",        ICON_EXT_LUA,       COLOR_LUA}, */
	/* {"lzh",        ICON_EXT_LZH,       COLOR_ARCHIVE}, */
	/* {"lzma",       ICON_EXT_LZMA,      COLOR_ARCHIVE}, */

	/* /1* M *1/ */
	/* {"m",          ICON_EXT_M,         COLOR_C}, */
	/* {"m4a",        ICON_EXT_M4A,       COLOR_AUDIO}, */
	/* {"m4v",        ICON_EXT_M4V,       COLOR_VIDEO}, */
	{"markdown",   ICON_EXT_MD,        COLOR_DOCS},
	/* {"mat",        ICON_EXT_MAT,       COLOR_C}, */
	{"md",         ICON_EXT_MD,        COLOR_DOCS},
	/* {"mk",         ICON_EXT_MK,        0}, */
	/* {"mkv",        ICON_EXT_MKV,       COLOR_VIDEO}, */
	/* {"mov",        ICON_EXT_MOV,       COLOR_VIDEO}, */
	/* {"mp3",        ICON_EXT_MP3,       COLOR_AUDIO}, */
	/* {"mp4",        ICON_EXT_MP4,       COLOR_VIDEO1}, */
	/* {"mpeg",       ICON_EXT_MPEG,      COLOR_VIDEO}, */
	/* {"mpg",        ICON_EXT_MPG,       COLOR_VIDEO}, */
	/* {"msi",        ICON_EXT_MSI,       0}, */

	/* /1* N *1/ */
	/* {"nix",        ICON_EXT_NIX,       COLOR_FSHARP}, */

	/* /1* O *1/ */
	/* {"o",          ICON_EXT_O,         0}, */
	/* {"ogg",        ICON_EXT_OGG,       COLOR_AUDIO}, */
	/* {"opus",       ICON_EXT_OPUS,      COLOR_AUDIO}, */
	/* {"opdownload", ICON_EXT_ODOWNLOAD, 0}, */
	/* {"out",        ICON_EXT_OUT,       0}, */

	/* /1* P *1/ */
	/* {"part",       ICON_EXT_PART,      0}, */
	/* {"patch",      ICON_EXT_PATCH,     0}, */
	/* {"pdf",        ICON_EXT_PDF,       COLOR_DOCS}, */
	/* {"pgn",        ICON_EXT_PGN,       0}, */
	/* {"php",        ICON_EXT_PHP,       0}, */
	/* {"png",        ICON_EXT_PNG,       COLOR_IMAGE}, */
	/* {"ppt",        ICON_EXT_PPT,       0}, */
	/* {"pptx",       ICON_EXT_PPTX,      0}, */
	/* {"psb",        ICON_EXT_PSB,       0}, */
	/* {"psd",        ICON_EXT_PSD,       0}, */
	/* {"py",         ICON_EXT_PY,        COLOR_PYTHON}, */
	/* {"pyc",        ICON_EXT_PYC,       COLOR_PYTHON}, */
	/* {"pyd",        ICON_EXT_PYD,       COLOR_PYTHON}, */
	/* {"pyo",        ICON_EXT_PYO,       COLOR_PYTHON}, */

	/* /1* Q *1/ */

	/* /1* R *1/ */
	/* {"rar",        ICON_EXT_RAR,       COLOR_ARCHIVE}, */
	/* {"rb",         ICON_EXT_RB,        COLOR_RUBY}, */
	/* {"rc",         ICON_EXT_RC,        0}, */
	/* {"rom",        ICON_EXT_ROM,       0}, */
	/* {"rpm",        ICON_EXT_RPM,       COLOR_ARCHIVE}, */
	/* {"rss",        ICON_EXT_RSS,       0}, */
	/* {"rtf",        ICON_EXT_RTF,       0}, */

	/* /1* S *1/ */
	/* {"sass",       ICON_EXT_SASS,      COLOR_CSS}, */
	/* {"scss",       ICON_EXT_SCSS,      COLOR_CSS}, */
	/* {"so",         ICON_EXT_SO,        0}, */
	/* {"scala",      ICON_EXT_SCALA,     COLOR_SCALA}, */
	/* {"sh",         ICON_EXT_SH,        COLOR_SHELL}, */
	/* {"slim",       ICON_EXT_SLIM,      COLOR_DOCUMENT}, */
	/* {"sln",        ICON_EXT_SLN,       0}, */
	/* {"sql",        ICON_EXT_SQL,       0}, */
	/* {"srt",        ICON_EXT_SRT,       0}, */
	/* {"sty",        ICON_EXT_STY,       0}, */
	/* {"sub",        ICON_EXT_SUB,       0}, */
	/* {"svg",        ICON_EXT_SVG,       COLOR_IMAGE}, */

	/* /1* T *1/ */
	/* {"tar",        ICON_EXT_TAR,       COLOR_ARCHIVE}, */
	/* {"tex",        ICON_EXT_TEX,       0}, */
	/* {"tgz",        ICON_EXT_TGZ,       COLOR_ARCHIVE}, */
	/* {"ts",         ICON_EXT_TS,        COLOR_JAVASCRIPT}, */
	/* {"tsx",        ICON_EXT_TSX,       COLOR_REACT}, */
	/* {"txt",        ICON_EXT_TXT,       COLOR_DOCUMENT}, */
	/* {"txz",        ICON_EXT_TXZ,       COLOR_ARCHIVE}, */

	/* /1* U *1/ */

	/* /1* V *1/ */
	/* {"vid",        ICON_EXT_VID,       COLOR_VIDEO}, */
	/* {"vim",        ICON_EXT_VIM,       COLOR_VIM}, */
	/* {"vimrc",      ICON_EXT_VIMRC,     COLOR_VIM}, */
	/* {"vtt",        ICON_EXT_SRT,       0}, */

	/* /1* W *1/ */
	/* {"wav",        ICON_EXT_WAV,       COLOR_AUDIO}, */
	/* {"webm",       ICON_EXT_WEBM,      COLOR_VIDEO}, */
	/* {"webp",       ICON_EXT_WEBP,      COLOR_IMAGE}, */
	/* {"wma",        ICON_EXT_WMA,       COLOR_AUDIO}, */
	/* {"wmv",        ICON_EXT_WMV,       COLOR_VIDEO}, */

	/* /1* X *1/ */
	/* {"xbps",       ICON_EXT_XBPS,      COLOR_ARCHIVE}, */
	/* {"xcf",        ICON_EXT_XCF,       COLOR_IMAGE}, */
	/* {"xhtml",      ICON_EXT_XHTML,     0}, */
	/* {"xls",        ICON_EXT_XLS,       0}, */
	/* {"xlsx",       ICON_EXT_XLSX,      0}, */
	/* {"xml",        ICON_EXT_XML,       0}, */
	/* {"xz",         ICON_EXT_XZ,        COLOR_ARCHIVE}, */

	/* /1* Y *1/ */
	/* {"yaml",       ICON_EXT_YAML,      COLOR_DOCUMENT}, */
	/* {"yml",        ICON_EXT_YML,       COLOR_DOCUMENT}, */

	/* /1* Z *1/ */
	/* {"zip",        ICON_EXT_ZIP,       COLOR_ARCHIVE}, */
	/* {"zsh",        ICON_EXT_ZSH,       COLOR_SHELL}, */
	/* {"zst",        ICON_EXT_ZST,       COLOR_ARCHIVE}, */

	/* Other */
};
#endif

#endif /* INCLUDE_ICONS_H */
