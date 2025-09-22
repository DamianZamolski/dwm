static const char* tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const float mfact = 0.55;
static const int lockfullscreen = 1;
static const int nmaster = 1;
static const int resizehints = 0;
static const int showbar = 1;
static const int topbar = 1;
static const unsigned int borderpx = 4;
static const unsigned int snap = 32;

static const char* fonts[] = {
  "monospace:size=21:antialias=true:autohint=true",
};

static const char* colors[][3] = {
  [SchemeNorm] = { "#000000", "#fafafa", "#000000" },
  [SchemeSel] = { "#000000", "#50a14f", "#50a14f" },
};

static const Layout layouts[] = {
  { "[]=", tile },
  { "[M]", monocle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                                                                                                         \
  { MODKEY, KEY, view, { .ui = 1 << TAG } }, { MODKEY | ControlMask, KEY, toggleview, { .ui = 1 << TAG } }, { MODKEY | ShiftMask, KEY, tag, { .ui = 1 << TAG } }, \
  {                                                                                                                                                               \
    MODKEY | ControlMask | ShiftMask, KEY, toggletag,                                                                                                             \
    {                                                                                                                                                             \
      .ui = 1 << TAG                                                                                                                                              \
    }                                                                                                                                                             \
  }

static char dmenumon[2] = "0";

static const char* bambuStudio[] = { "bambu-studio", NULL };
static const char* discord[] = { "discord", NULL };
static const char* dmenuCmd[] = { "dmenu_run", NULL };
static const char* emoji[] = { "rofi", "-modi", "emoji", "-show", "emoji", NULL };
static const char* firefox[] = { "firefox-developer-edition", NULL };
static const char* gimp[] = { "gimp", NULL };
static const char* inkscape[] = { "inkscape", NULL };
static const char* searchModel[] = { "rofi-search-model", NULL };
static const char* openScad[] = { "openscad", NULL };
static const char* pwvucontrol[] = { "pwvucontrol", NULL };
static const char* rofi[] = { "rofi", "-show", "drun", NULL };
static const char* signalCmd[] = { "signal-desktop", NULL };
static const char* steam[] = { "steam", NULL };
static const char* teams[] = { "teams-for-linux", NULL };
static const char* terminalCmd[] = { "alacritty", NULL, NULL };
static const char* thunderbird[] = { "thunderbird", NULL };
static const char* vlc[] = { "vlc", NULL };

static const char* screenshot[] = { "screenshot", NULL };
static const char* screenshotToClipboard[] = { "screenshot-to-clipboard", NULL };
static const char* selectionScreenshot[] = { "selection-screenshot", NULL };
static const char* selectionScreenshotToClipboard[] = { "selection-screenshot-to-clipboard", NULL };

static const char* decreaseVolume[] = { "wpctl", "set-volume", "@DEFAULT_SINK@", "1%-", NULL };
static const char* increaseVolume[] = { "wpctl", "set-volume", "@DEFAULT_SINK@", "1%+", NULL };
static const char* muteVolume[] = { "wpctl", "set-volume", "@DEFAULT_SINK@", "0%", NULL };
static const char* setMaxVolume[] = { "wpctl", "set-volume", "@DEFAULT_SINK@", "100%", NULL };

static const char* increaseBrightness[] = { "xbacklight", "-inc", "1", NULL };
static const char* decreaseBrightness[] = { "xbacklight", "-dec", "1", NULL };
static const char* setMaxBrightness[] = { "xbacklight", "-set", "100", NULL };

static const Key keys[] = {
  TAGKEYS(XK_1, 0),
  TAGKEYS(XK_2, 1),
  TAGKEYS(XK_3, 2),
  TAGKEYS(XK_4, 3),
  TAGKEYS(XK_5, 4),
  TAGKEYS(XK_6, 5),
  TAGKEYS(XK_7, 6),
  TAGKEYS(XK_8, 7),
  TAGKEYS(XK_9, 8),
  { 0, XK_Print, spawn, { .v = screenshotToClipboard } },
  { ControlMask | ShiftMask, XK_Print, spawn, { .v = selectionScreenshot } },
  { ControlMask, XK_Print, spawn, { .v = screenshot } },
  { MODKEY | ShiftMask, XK_0, tag, { .ui = ~0 } },
  { MODKEY | ShiftMask, XK_comma, tagmon, { .i = -1 } },
  { MODKEY | ShiftMask, XK_Down, spawn, { .v = muteVolume } },
  { MODKEY | ShiftMask, XK_period, tagmon, { .i = +1 } },
  { MODKEY | ShiftMask, XK_q, quit, { 0 } },
  { MODKEY | ShiftMask, XK_Right, spawn, { .v = setMaxBrightness } },
  { MODKEY | ShiftMask, XK_s, spawn, { .v = steam } },
  { MODKEY | ShiftMask, XK_space, setlayout, { 0 } },
  { MODKEY | ShiftMask, XK_t, spawn, { .v = teams } },
  { MODKEY | ShiftMask, XK_Up, spawn, { .v = setMaxVolume } },
  { MODKEY, XK_0, view, { .ui = ~0 } },
  { MODKEY, XK_b, spawn, { .v = bambuStudio } },
  { MODKEY, XK_comma, focusmon, { .i = -1 } },
  { MODKEY, XK_d, spawn, { .v = discord } },
  { MODKEY, XK_Down, spawn, { .v = decreaseVolume } },
  { MODKEY, XK_e, spawn, { .v = emoji } },
  { MODKEY, XK_f, spawn, { .v = firefox } },
  { MODKEY, XK_g, spawn, { .v = gimp } },
  { MODKEY, XK_h, setmfact, { .f = -0.05 } },
  { MODKEY, XK_i, spawn, { .v = inkscape } },
  { MODKEY, XK_j, focusstack, { .i = +1 } },
  { MODKEY, XK_k, focusstack, { .i = -1 } },
  { MODKEY, XK_l, setmfact, { .f = +0.05 } },
  { MODKEY, XK_Left, spawn, { .v = decreaseBrightness } },
  { MODKEY, XK_m, spawn, { .v = searchModel } },
  { MODKEY, XK_o, spawn, { .v = openScad } },
  { MODKEY, XK_p, spawn, { .v = pwvucontrol } },
  { MODKEY, XK_period, focusmon, { .i = +1 } },
  { MODKEY, XK_q, killclient, { 0 } },
  { MODKEY, XK_r, spawn, { .v = rofi } },
  { MODKEY, XK_Return, spawn, { .v = terminalCmd } },
  { MODKEY, XK_Right, spawn, { .v = increaseBrightness } },
  { MODKEY, XK_s, spawn, { .v = signalCmd } },
  { MODKEY, XK_space, zoom, { 0 } },
  { MODKEY, XK_t, spawn, { .v = thunderbird } },
  { MODKEY, XK_Tab, view, { 0 } },
  { MODKEY, XK_Up, spawn, { .v = increaseVolume } },
  { MODKEY, XK_v, spawn, { .v = vlc } },
  { ShiftMask, XK_Print, spawn, { .v = selectionScreenshotToClipboard } },
};

static const Button buttons[] = { 0 };
static const Rule rules[] = { 0 };
