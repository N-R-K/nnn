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

// Top level and common icons
#define ICON_ARCHIVE       ICON_STR("\ue27f", "\uf53b", "📦")
#define ICON_BRIEFCASE     ICON_STR("\ue187", "\uf5d5", "💼")
#define ICON_C             ICON_STR("\uedb1", "\ue61e", "🇨 ")
#define ICON_CHANGELOG     ICON_STR("\ue292", "\uf7d9", "🔺")
#define ICON_CHESS         ICON_STR("", "\uf639", "")
#define ICON_CLOJURE       ICON_STR("\uedb4", "\ue76a", "")
#define ICON_CONFIGURE     ICON_STR("\ue8df", "\uf423", "🔧")
#define ICON_CPLUSPLUS     ICON_STR("\uedb8", "\ue61d", ICON_C)
#define ICON_DATABASE      ICON_STR("\uedc0", "\uf6b7", "🗃️ ")
#define ICON_DESKTOP       ICON_STR("\ue1cd", "\ufcbe", "🖥️ ")
#define ICON_DOCUMENT      ICON_STR("\ue1bc", "\uf718", "🗒 ")
#define ICON_DOWNLOADS     ICON_STR("\ue0f9", "\uf5d7", "📥")
#define ICON_ENCRYPT       ICON_STR("", "\uf805", "🔒")
#define ICON_FSHARP        ICON_STR("\ueaae", "\ue7a7", "")
#define ICON_GIT           ICON_STR("\ue28b", "\ue5fb", "🌱")
#define ICON_HASKELL       ICON_STR("", "\ue777", "")
#define ICON_HTML          ICON_STR("\ue282", "\uf72d", "")
#define ICON_JAVA          ICON_STR("\uede3", "\ue738", "☕")
#define ICON_JAVASCRIPT    ICON_STR("\ue282", "\uf81d", "")
#define ICON_LICENSE       ICON_STR("\ue2af", "\uf718", "⚖️ ")
#define ICON_LINUX         ICON_STR("\ue23a", "\uf83c", "🐧")
#define ICON_MAKEFILE      ICON_STR("\ue7a2", "\uf68c", "🛠 ")
#define ICON_MANUAL        ICON_STR("\ue799", "\uf5bd", "❓")
#define ICON_MS_EXCEL      ICON_STR("\ue851", "\uf71a", ICON_WORDDOC)
#define ICON_MUSIC         ICON_STR("\ue0e2", "\uf832", "🎧")
#define ICON_MUSICFILE     ICON_STR("\ue280", "\uf886", ICON_MUSIC)
#define ICON_OPTICALDISK   ICON_STR("\uecd3", "\ue271", "💿")
#define ICON_PDF           ICON_STR("\ue27a", "\uf724", "📕")
#define ICON_PHOTOSHOP     ICON_STR("\ueabf", "\ue7b8", ICON_PICTUREFILE)
#define ICON_PICTUREFILE   ICON_STR("\ue27e", "\uf71e", ICON_PICTURES)
#define ICON_PICTURES      ICON_STR("\ue4fb", "\uf753", "🎨")
#define ICON_PLAYLIST      ICON_STR(ICON_MUSICFILE, "\uf910", "")
#define ICON_POWERPOINT    ICON_STR("\ue84f", "\uf726", "📊")
#define ICON_PUBLIC        ICON_STR("\ue0fc", "\ue5ff", "👀")
#define ICON_PYTHON        ICON_STR("\uee10", "\ue235", "🐍")
#define ICON_REACT         ICON_STR("\ue849", "\ue625", ICON_JAVASCRIPT)
#define ICON_RUBY          ICON_STR("\uee15", "\ue23e", "💎")
#define ICON_SASS          ICON_STR("", "\ue603", "")
#define ICON_SCRIPT        ICON_STR("\uee1d", "\ue795", "📜")
#define ICON_SUBTITLE      ICON_STR("\ue1ad", "\uf679", "💬")
#define ICON_TEMPLATES     ICON_STR("\ue18f", "\ufac6", "📎")
#define ICON_TEX           ICON_STR("\ue755", "\ufb68", ICON_DOCUMENT)
#define ICON_VIDEOFILE     ICON_STR("\ue281", "\uf72a", ICON_VIDEOS)
#define ICON_VIDEOS        ICON_STR("\ue0e9", "\uf72f", "🎞 ")
#define ICON_VIM           ICON_STR("\ueacc", "\ue62b", "")
#define ICON_WORDDOC       ICON_STR("\ue850", "\uf72b", "📘")

#define ICON_EXT_ASM       ICON_STR("\ue8d5", "", "")
#define ICON_EXT_BIN       ICON_STR("\ue073", "\uf471", "📓")
#define ICON_EXT_COFFEE    ICON_STR("\uedb7", "\ue751", "")
#define ICON_EXT_CSS       ICON_STR("\uedbb", "\ue749", "🦋")
#define ICON_EXT_DEB       ICON_STR("\uedc1", "\ue77d", ICON_LINUX)
#define ICON_EXT_DIFF      ICON_STR("\ue7c3", "\uf440", "📋")
#define ICON_EXT_GO        ICON_STR("\uedd0", "\ufcd1", "")
#define ICON_EXT_JSON      ICON_STR(ICON_JAVASCRIPT, "\ufb25", ICON_JAVASCRIPT)
#define ICON_EXT_LUA       ICON_STR("\ue77e", "\ue620", "🌘")
#define ICON_EXT_M         ICON_STR("", "\ufd1c", "📊")
#define ICON_EXT_MAT       ICON_STR("", "\uf0ce", "")
#define ICON_EXT_MD        ICON_STR("\uea45", "\ue609", "📝")
#define ICON_EXT_MSI       ICON_STR("\ue238", "\uf871", "🪟")
#define ICON_EXT_NIX       ICON_STR("", "\uf313", "")
#define ICON_EXT_PATCH     ICON_STR("\ue7c4", "\uf440", "🩹")
#define ICON_EXT_PHP       ICON_STR("\uee09", "\ue73d", "🌐")
#define ICON_EXT_ROM       ICON_STR("\ue101", "\uf795", "")
#define ICON_EXT_RSS       ICON_STR("\ue204", "\uf96b", "📡")
#define ICON_EXT_RTF       ICON_STR(ICON_PDF, "\uf724", ICON_PDF)
#define ICON_EXT_SCALA     ICON_STR("\uee1b", "\ue737", "")
#define ICON_EXT_SLN       ICON_STR("\uea13", "\ue70c", "")
#define ICON_EXT_TS        ICON_STR("\ue73f", "\ue628", "")

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
/*
 * All entries are case-insensitive
 * Any entry with empty icon gets removed by the hash-table generator
 */
static const struct icon_pair icons_ext[] = {
	/* Numbers */
	{"1",          ICON_MANUAL,         COLOR_DOCS},
	{"7z",         ICON_ARCHIVE,        COLOR_ARCHIVE},

	/* A */
	{"a",          ICON_MANUAL,         0},
	{"apk",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"asm",        ICON_EXT_ASM,        0},
	{"aup",        ICON_MUSICFILE,      COLOR_AUDIO},
	{"avi",        ICON_VIDEOFILE,      COLOR_VIDEO},

	/* B */
	{"bat",        ICON_SCRIPT,         0},
	{"bib",        ICON_TEX,            0},
	{"bin",        ICON_EXT_BIN,        0},
	{"bmp",        ICON_PICTUREFILE,    COLOR_IMAGE},
	{"bz2",        ICON_ARCHIVE,        COLOR_ARCHIVE},

	/* C */
	{"c",          ICON_C,              COLOR_C},
	{"c++",        ICON_CPLUSPLUS,      COLOR_C},
	{"cabal",      ICON_HASKELL,        COLOR_VIDEO},
	{"cab",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"cbr",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"cbz",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"cc",         ICON_CPLUSPLUS,      COLOR_C},
	{"class",      ICON_JAVA,           COLOR_JAVA},
	{"clj",        ICON_CLOJURE,        0},
	{"cljc",       ICON_CLOJURE,        0},
	{"cljs",       ICON_CLOJURE,        0},
	{"cls",        ICON_TEX,            0},
	{"cmake",      ICON_MAKEFILE,       0},
	{"coffee",     ICON_EXT_COFFEE,     0},
	{"conf",       ICON_CONFIGURE,      0},
	{"cpio",       ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"cpp",        ICON_CPLUSPLUS,      COLOR_C},
	{"css",        ICON_EXT_CSS,        COLOR_CSS},
	{"cue",        ICON_PLAYLIST,       COLOR_AUDIO},
	{"cvs",        ICON_CONFIGURE,      0},
	{"cxx",        ICON_CPLUSPLUS,      COLOR_C},

	/* D */
	{"db",         ICON_DATABASE,       0},
	{"deb",        ICON_EXT_DEB,        COLOR_ARCHIVE},
	{"diff",       ICON_EXT_DIFF,       0},
	{"dll",        ICON_SCRIPT,         0},
	{"doc",        ICON_WORDDOC,        COLOR_DOCUMENT},
	{"docx",       ICON_WORDDOC,        COLOR_DOCUMENT},

	/* E */
	{"ejs",        ICON_JAVASCRIPT,     COLOR_JAVASCRIPT},
	{"elf",        ICON_LINUX,          0},
	{"epub",       ICON_PDF,            COLOR_DOCS},
	{"exe",        ICON_EXEC,           0},

	/* F */
	{"f#",         ICON_FSHARP,         COLOR_FSHARP},
	{"fen",        ICON_CHESS,          0},
	{"flac",       ICON_MUSICFILE,      COLOR_AUDIO1},
	{"flv",        ICON_VIDEOFILE,      COLOR_VIDEO},
	{"fs",         ICON_FSHARP,         COLOR_FSHARP},
	{"fsi",        ICON_FSHARP,         COLOR_FSHARP},
	{"fsscript",   ICON_FSHARP,         COLOR_FSHARP},
	{"fsx",        ICON_FSHARP,         COLOR_FSHARP},

	/* G */
	{"gem",        ICON_RUBY,           COLOR_RUBY},
	{"gif",        ICON_PICTUREFILE,    COLOR_IMAGE},
	{"go",         ICON_EXT_GO,         0},
	{"gpg",        ICON_ENCRYPT,        COLOR_ARCHIVE},
	{"gz",         ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"gzip",       ICON_ARCHIVE,        COLOR_ARCHIVE},

	/* H */
	{"h",          ICON_C,              COLOR_C},
	{"hh",         ICON_CPLUSPLUS,      COLOR_C},
	{"hpp",        ICON_CPLUSPLUS,      COLOR_C},
	{"hs",         ICON_HASKELL,        COLOR_VIM},
	{"htaccess",   ICON_CONFIGURE,      0},
	{"htpasswd",   ICON_CONFIGURE,      0},
	{"htm",        ICON_HTML,           0},
	{"html",       ICON_HTML,           0},
	{"hxx",        ICON_CPLUSPLUS,      COLOR_C},

	/* I */
	{"ico",        ICON_PICTUREFILE,    COLOR_IMAGE},
	{"ini",        ICON_CONFIGURE,      0},
	{"img",        ICON_OPTICALDISK,    COLOR_ARCHIVE},
	{"iso",        ICON_OPTICALDISK,    COLOR_ARCHIVE},

	/* J */
	{"jar",        ICON_JAVA,           COLOR_JAVA},
	{"java",       ICON_JAVA,           COLOR_JAVA},
	{"jl",         ICON_CONFIGURE,      0},
	{"jpeg",       ICON_PICTUREFILE,    COLOR_IMAGE},
	{"jpg",        ICON_PICTUREFILE,    COLOR_IMAGE},
	{"js",         ICON_JAVASCRIPT,     COLOR_JAVASCRIPT},
	{"json",       ICON_EXT_JSON,       COLOR_JAVASCRIPT},
	{"jsx",        ICON_REACT,          COLOR_REACT},

	/* K */

	/* L */
	{"lha",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"lhs",        ICON_HASKELL,        COLOR_VIM},
	{"log",        ICON_DOCUMENT,       0},
	{"lua",        ICON_EXT_LUA,        COLOR_LUA},
	{"lzh",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"lzma",       ICON_ARCHIVE,        COLOR_ARCHIVE},

	/* M */
	{"m",          ICON_EXT_M,          COLOR_C},
	{"m4a",        ICON_MUSICFILE,      COLOR_AUDIO},
	{"m4v",        ICON_VIDEOFILE,      COLOR_VIDEO},
	{"markdown",   ICON_EXT_MD,         COLOR_DOCS},
	{"mat",        ICON_EXT_MAT,        COLOR_C},
	{"md",         ICON_EXT_MD,         COLOR_DOCS},
	{"mk",         ICON_MAKEFILE,       0},
	{"mkv",        ICON_VIDEOFILE,      COLOR_VIDEO},
	{"mov",        ICON_VIDEOFILE,      COLOR_VIDEO},
	{"mp3",        ICON_MUSICFILE,      COLOR_AUDIO},
	{"mp4",        ICON_VIDEOFILE,      COLOR_VIDEO1},
	{"mpeg",       ICON_VIDEOFILE,      COLOR_VIDEO},
	{"mpg",        ICON_VIDEOFILE,      COLOR_VIDEO},
	{"msi",        ICON_EXT_MSI,        0},

	/* N */
	{"nix",        ICON_EXT_NIX,        COLOR_FSHARP},

	/* O */
	{"o",          ICON_MANUAL,         0},
	{"ogg",        ICON_MUSICFILE,      COLOR_AUDIO},
	{"opus",       ICON_MUSICFILE,      COLOR_AUDIO},
	{"opdownload", ICON_DOWNLOADS,      0},
	{"out",        ICON_LINUX,          0},

	/* P */
	{"part",       ICON_DOWNLOADS,      0},
	{"patch",      ICON_EXT_PATCH,      0},
	{"pdf",        ICON_PDF,            COLOR_DOCS},
	{"pgn",        ICON_CHESS,          0},
	{"php",        ICON_EXT_PHP,        0},
	{"png",        ICON_PICTUREFILE,    COLOR_IMAGE},
	{"ppt",        ICON_POWERPOINT,     0},
	{"pptx",       ICON_POWERPOINT,     0},
	{"psb",        ICON_PHOTOSHOP,      0},
	{"psd",        ICON_PHOTOSHOP,      0},
	{"py",         ICON_PYTHON,        COLOR_PYTHON},
	{"pyc",        ICON_PYTHON,        COLOR_PYTHON},
	{"pyd",        ICON_PYTHON,        COLOR_PYTHON},
	{"pyo",        ICON_PYTHON,        COLOR_PYTHON},

	/* Q */

	/* R */
	{"rar",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"rb",         ICON_RUBY,           COLOR_RUBY},
	{"rc",         ICON_CONFIGURE,      0},
	{"rom",        ICON_EXT_ROM,        0},
	{"rpm",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"rss",        ICON_EXT_RSS,        0},
	{"rtf",        ICON_EXT_RTF,        0},

	/* S */
	{"sass",       ICON_SASS,           COLOR_CSS},
	{"scss",       ICON_SASS,           COLOR_CSS},
	{"so",         ICON_MANUAL,         0},
	{"scala",      ICON_EXT_SCALA,      COLOR_SCALA},
	{"sh",         ICON_SCRIPT,         COLOR_SHELL},
	{"slim",       ICON_SCRIPT,         COLOR_DOCUMENT},
	{"sln",        ICON_EXT_SLN,        0},
	{"sql",        ICON_DATABASE,       0},
	{"srt",        ICON_SUBTITLE,       0},
	{"sty",        ICON_TEX,            0},
	{"sub",        ICON_SUBTITLE,       0},
	{"svg",        ICON_PICTUREFILE,    COLOR_IMAGE},

	/* T */
	{"tar",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"tex",        ICON_TEX,            0},
	{"tgz",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"ts",         ICON_EXT_TS,        COLOR_JAVASCRIPT},
	{"tsx",        ICON_REACT,          COLOR_REACT},
	{"txt",        ICON_DOCUMENT,       COLOR_DOCUMENT},
	{"txz",        ICON_ARCHIVE,        COLOR_ARCHIVE},

	/* U */

	/* V */
	{"vid",        ICON_VIDEOFILE,      COLOR_VIDEO},
	{"vim",        ICON_VIM,            COLOR_VIM},
	{"vimrc",      ICON_VIM,            COLOR_VIM},
	{"vtt",        ICON_SUBTITLE,       0},

	/* W */
	{"wav",        ICON_MUSICFILE,      COLOR_AUDIO},
	{"webm",       ICON_VIDEOFILE,      COLOR_VIDEO},
	{"webp",       ICON_PICTUREFILE,    COLOR_IMAGE},
	{"wma",        ICON_VIDEOFILE,      COLOR_AUDIO},
	{"wmv",        ICON_VIDEOFILE,      COLOR_VIDEO},

	/* X */
	{"xbps",       ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"xcf",        ICON_PICTUREFILE,    COLOR_IMAGE},
	{"xhtml",      ICON_HTML,           0},
	{"xls",        ICON_MS_EXCEL,       0},
	{"xlsx",       ICON_MS_EXCEL,       0},
	{"xml",        ICON_HTML,           0},
	{"xz",         ICON_ARCHIVE,        COLOR_ARCHIVE},

	/* Y */
	{"yaml",       ICON_CONFIGURE,      COLOR_DOCUMENT},
	{"yml",        ICON_CONFIGURE,      COLOR_DOCUMENT},

	/* Z */
	{"zip",        ICON_ARCHIVE,        COLOR_ARCHIVE},
	{"zsh",        ICON_SCRIPT,         COLOR_SHELL},
	{"zst",        ICON_ARCHIVE,        COLOR_ARCHIVE},

	/* Other */
};
#endif

#endif /* INCLUDE_ICONS_H */
