static const unsigned int borderpx = 4;
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
static const float mfact = 0.55;
static const int nmaster = 1;
static const int resizehints = 0;
static const int lockfullscreen = 1;
static const unsigned int snap = 32;
static const int showbar = 1;
static const int topbar = 1;
static const char *fonts[] = {"Source Code Pro:pixelsize=16:antialias=true:autohint=true"};

static const char *colors[][3] = {
  [SchemeNorm] = {"#000000", "#fafafa", "#000000"},
  [SchemeSel] = {"#000000", "#50a14f", "#50a14f"},
};

static const Layout layouts[] = {
  {"[]=", tile},
  {"[M]", monocle},
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
{MODKEY, KEY, view, {.ui = 1 << TAG}}, \
{MODKEY|ControlMask, KEY, toggleview, {.ui = 1 << TAG}}, \
{MODKEY|ShiftMask, KEY, tag, {.ui = 1 << TAG}}, \
{MODKEY|ControlMask|ShiftMask, KEY, toggletag, {.ui = 1 << TAG}}

static char dmenumon[2] = "0";
static const char *dmenuCmd[] = {"dmenu_run", NULL};

static const char *discordCmd[] = {"discord", NULL};
static const char *firefoxCmd[] = {"firefox-developer-edition", NULL};
static const char *intellijCmd[] = {"intellij-idea-ultimate-edition", NULL};
static const char *nuclearCmd[] = {"nuclear", NULL};
static const char *rocketchatCmd[] = {"rocketchat-desktop", NULL};
static const char *signalCmd[] = {"signal-desktop", NULL};
static const char *stCmd[] = {"st", NULL};
static const char *thunderbirdCmd[] = {"thunderbird", NULL};
static const char *webstormCmd[] = {"webstorm", NULL};

static const char *screenshotCmd[] = {"screenshot", NULL};
static const char *screenshotToClipboardCmd[] = {"screenshot-to-clipboard", NULL};
static const char *selectionScreenshotCmd[] = {"selection-screenshot", NULL};
static const char *selectionScreenshotToClipboardCmd[] = {"selection-screenshot-to-clipboard", NULL};

static const char *increaseVolumeCmd[] = {"amixer", "-c", "1", "sset", "Master", "1%+", NULL};
static const char *decreaseVolumeCmd[] = {"amixer", "-c", "1", "sset", "Master", "1%-", NULL};
static const char *setMaxVolumeCmd[] = {"amixer", "-c", "1", "sset", "Master", "100%", NULL};
static const char *muteVolumeCmd[] = {"amixer", "-c", "1", "sset", "Master", "0%", NULL};

static const char *increaseBrightnessCmd[] = {"xbacklight", "-inc", "1", NULL};
static const char *decreaseBrightnessCmd[] = {"xbacklight", "-dec", "1", NULL};
static const char *setMaxBrightnessCmd[] = {"xbacklight", "-set", "100", NULL};

static const Key keys[] = {
  {MODKEY, XK_Return, spawn, {.v = stCmd}},
  {MODKEY, XK_m, spawn, {.v = dmenuCmd}},

  {MODKEY, XK_d, spawn, {.v = discordCmd}},
  {MODKEY, XK_f, spawn, {.v = firefoxCmd}},
  {MODKEY, XK_i, spawn, {.v = intellijCmd}},
  {MODKEY, XK_n, spawn, {.v = nuclearCmd}},
  {MODKEY, XK_r, spawn, {.v = rocketchatCmd}},
  {MODKEY, XK_s, spawn, {.v = signalCmd}},
  {MODKEY, XK_t, spawn, {.v = thunderbirdCmd}},
  {MODKEY, XK_w, spawn, {.v = webstormCmd}},

  {MODKEY, XK_Print, spawn, {.v = screenshotCmd}},
  {MODKEY|ControlMask, XK_Print, spawn, {.v = screenshotToClipboardCmd}},
  {MODKEY|ShiftMask, XK_Print, spawn, {.v = selectionScreenshotCmd}},
  {MODKEY|ControlMask|ShiftMask, XK_Print, spawn, {.v = selectionScreenshotToClipboardCmd}},

  {MODKEY, XK_Up, spawn, {.v = increaseVolumeCmd}},
  {MODKEY, XK_Down, spawn, {.v = decreaseVolumeCmd}},
  {MODKEY|ShiftMask, XK_Up, spawn, {.v = setMaxVolumeCmd}},
  {MODKEY|ShiftMask, XK_Down, spawn, {.v = muteVolumeCmd}},

  {MODKEY, XK_Right, spawn, {.v = increaseBrightnessCmd}},
  {MODKEY, XK_Left, spawn, {.v = decreaseBrightnessCmd}},
  {MODKEY|ShiftMask, XK_Right, spawn, {.v = setMaxBrightnessCmd}},

  {MODKEY, XK_b, togglebar, {0}},
  {MODKEY, XK_j, focusstack, {.i = +1}},
  {MODKEY, XK_k, focusstack, {.i = -1}},
  {MODKEY, XK_h, setmfact, {.f = -0.05}},
  {MODKEY, XK_l, setmfact, {.f = +0.05}},
  {MODKEY, XK_Tab, view, {0}},
  {MODKEY, XK_q, killclient, {0}},
  {MODKEY, XK_space, zoom, {0}},
  {MODKEY|ShiftMask, XK_space, setlayout, {0}},
  {MODKEY, XK_0, view, {.ui = ~0}},
  {MODKEY|ShiftMask, XK_0, tag, {.ui = ~0}},
  {MODKEY, XK_comma, focusmon, {.i = -1}},
  {MODKEY, XK_period, focusmon, {.i = +1}},
  {MODKEY|ShiftMask, XK_comma, tagmon, {.i = -1}},
  {MODKEY|ShiftMask, XK_period, tagmon, {.i = +1}},
  {MODKEY|ShiftMask, XK_q, quit, {0}},
  TAGKEYS(XK_1, 0),
  TAGKEYS(XK_2, 1),
  TAGKEYS(XK_3, 2),
  TAGKEYS(XK_4, 3),
  TAGKEYS(XK_5, 4),
  TAGKEYS(XK_6, 5),
  TAGKEYS(XK_7, 6),
  TAGKEYS(XK_8, 7),
  TAGKEYS(XK_9, 8),
};

static const Button buttons[] = {0};
static const Rule rules[] = {0};
