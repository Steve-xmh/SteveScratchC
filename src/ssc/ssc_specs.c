#include "ssc_specs.h"

// 定义类型
ssc_cReg ssc_specs_categories[] = {
	{0,"undefined"		,"#D42828",NULL},
	{1,"Motion"			,"#5A7CE4",NULL},
	{2,"Looks"			,"#9A65E7",NULL},
	{3,"Sound"			,"#9A65E7",NULL},
	{4,"Pen"			,"#1EAA7C",NULL},
	{5,"Events"			,"#D89340",NULL},
	{6,"Control"		,"#F1B92A",NULL},
	{7,"Sensing"		,"#3CB5F2",NULL},
	{8,"Operators"		,"#6CC722",NULL},
	{9,"Data"			,"#FE8D26",NULL},
	{10,"More Blocks"	,"#FE8D26",NULL},
	{11,"Parameter"		,"#6957C1",NULL},
	{12,"List"			,"#DC6B32",NULL},
	{13,"SteveBlocks"	,"#11CCFF",NULL},
	{14,"KindForNoobs"	,"#22AAFF",NULL},
	{20,"Extension"		,"#4B4A60",NULL},
	{-1,NULL,NULL}//结束
};

// 定义模块
// - 空格
// -- 分割线
ssc_cmdReg ssc_specs_commands[] = {
	{N_("move %n steps"),						SSC_BT_CMD, 1, "forward:"},
	{N_("turn @turnRight %n degrees"),			SSC_BT_CMD, 1, "turnRight:"},
	{N_("turn @turnLeft %n degrees"),			SSC_BT_CMD, 1, "turnLeft:"},
	{"--",0,1,NULL},
	{N_("point in direction %d.direction"),		SSC_BT_CMD, 1, "heading:"},
	{N_("point towards %m.spriteOrMouse"),		SSC_BT_CMD, 1, "pointTowards:"},
	{"--",0,1,NULL},
	{N_("go to x:%n y:%n"),						SSC_BT_CMD, 1, "gotoX:y:"},
	{N_("go to %m.location"),					SSC_BT_CMD, 1, "gotoSpriteOrMouse:"},
	{N_("glide %n secs to x:%n y:%n"),			SSC_BT_CMD, 1, "glideSecs:toX:y:elapsed:from:"},
	{"--",0,1,NULL},
	{N_("change x by %n"),						SSC_BT_CMD, 1, "changeXposBy:"},
	{N_("set x to %n"),							SSC_BT_CMD, 1, "xpos:"},
	{N_("change y by %n"),						SSC_BT_CMD, 1, "changeYposBy:"},
	{N_("set y to %n"),							SSC_BT_CMD, 1, "ypos:"},
	{"--",0,1,NULL},
	{N_("if on edge, bounce"),					SSC_BT_CMD, 1, "bounceOffEdge"},
	{"-",0,1,NULL},
	{N_("set rotation style %m.rotationStyle"),	SSC_BT_CMD, 1, "setRotationStyle"},
	{"--",0,1,NULL},
	{N_("x position"),							SSC_BT_NUM, 1, "xpos"},
	{N_("y position"),							SSC_BT_NUM, 1, "ypos"},
	{N_("direction"),							SSC_BT_NUM, 1, "heading"},

	// looks
	{N_("say %s for %n secs"),					SSC_BT_CMD, 2, "say:duration:elapsed:from:"},
	{N_("say %s"),								SSC_BT_CMD, 2, "say:"},
	{N_("think %s for %n secs"),				SSC_BT_CMD, 2, "think:duration:elapsed:from:"},
	{N_("think %s"),							SSC_BT_CMD, 2, "think:"},
	{"-",0,2,NULL},
	{N_("show"),								SSC_BT_CMD, 2, "show"},
	{N_("hide"),								SSC_BT_CMD, 2, "hide"},
	{"-",0,2,NULL},
	{N_("switch costume to %m.costume"),		SSC_BT_CMD, 2, "lookLike:"},
	{N_("next costume"),						SSC_BT_CMD, 2, "nextCostume"},
	{N_("switch backdrop to %m.backdrop"),		SSC_BT_CMD, 2, "startScene"},
	{"-",0,2,NULL},
	{N_("change %m.effect effect by %n"),		SSC_BT_CMD, 2, "changeGraphicEffect:by:"},
	{N_("set %m.effect effect to %n"),			SSC_BT_CMD, 2, "setGraphicEffect:to:"},
	{N_("clear graphic effects"),				SSC_BT_CMD, 2, "filterReset"},
	{"-",0,2,NULL},
	{N_("change size by %n"),					SSC_BT_CMD, 2, "changeSizeBy"},
	{N_("set size to %n%"),						SSC_BT_CMD, 2, "setSizeTo:"},
	{"-",0,2,NULL},
	{N_("go to front"),							SSC_BT_CMD, 2, "comeToFront"},
	{N_("go back %n layers"),					SSC_BT_CMD, 2, "goBackByLayers:"},
	{"-",0,2,NULL},
	{N_("costume #"),							SSC_BT_NUM, 2, "costumeIndex"},
	{N_("backdrop name"),						SSC_BT_NUM, 2, "sceneName"},
	{N_("size"),								SSC_BT_NUM, 2, "scale"},

	// stage looks
	{N_("switch backdrop to %m.backdrop"),			SSC_BT_CMD, 102, "startScene"},
	{N_("switch backdrop to %m.backdrop and wait"), SSC_BT_CMD, 102, "startSceneAndWait"},
	{N_("next backdrop"),							SSC_BT_CMD, 102, "nextScene"},
	{"-",0,102,NULL},
	{N_("change %m.effect effect by %n"),		SSC_BT_CMD, 102, "changeGraphicEffect:by:"},
	{N_("set %m.effect effect to %n"),			SSC_BT_CMD, 102, "setGraphicEffect:to:"},
	{N_("clear graphic effects"),				SSC_BT_CMD, 102, "filterReset"},
	{"-",0,102,NULL},
	{N_("backdrop name"),						SSC_BT_NUM, 102, "sceneName"},
	{N_("backdrop #"),							SSC_BT_NUM, 102, "backgroundIndex"},

	// sound
	{N_("play sound %m.sound"),					SSC_BT_CMD, 3, "playSound:"},
	{N_("play sound %m.sound until done"),		SSC_BT_CMD, 3, "doPlaySoundAndWait"},
	{N_("stop all sounds"),						SSC_BT_CMD, 3, "stopAllSounds"},
	{"-",0,3,NULL},
	{N_("play drum %d.drum for %n beats"),		SSC_BT_CMD, 3, "playDrum"},
	{N_("rest for %n beats"),					SSC_BT_CMD, 3, "rest:elapsed:from:"},
	{"-",0,3,NULL},
	{N_("play note %d.note for %n beats"),		SSC_BT_CMD, 3, "noteOn:duration:elapsed:from:"},
	{N_("set instrument to %d.instrument"),		SSC_BT_CMD, 3, "instrument:"},

	{"-",0,3,NULL},
	{N_("change volume by %n"),					SSC_BT_CMD, 3, "changeVolumeBy:"},
	{N_("set volume to %n%"),					SSC_BT_CMD, 3, "setVolumeTo:"},
	{N_("volume"),								SSC_BT_NUM, 3, "volume"},
	{"-",0,3,NULL},
	{N_("change tempo by %n"),					SSC_BT_CMD, 3, "changeTempoBy:"},
	{N_("set tempo to %n bpm"),					SSC_BT_CMD, 3, "setTempoTo:"},
	{N_("tempo"),								SSC_BT_NUM, 3,  "tempo"},

	// pen
	{N_("clear"),								SSC_BT_CMD, 4, "clearPenTrails"},
	{"-",0,4,NULL},
	{N_("stamp"),								SSC_BT_CMD, 4, "stampCostume"},
	{"-",0,4,NULL},
	{N_("pen down"),							SSC_BT_CMD, 4, "putPenDown"},
	{N_("pen up"),								SSC_BT_CMD, 4, "putPenUp"},
	{"-",0,4,NULL},
	{N_("set pen color to %c"),					SSC_BT_CMD, 4, "penColor:"},
	{N_("change pen color by %n"),				SSC_BT_CMD, 4, "changePenHueBy:"},
	{N_("set pen color to %n"),					SSC_BT_CMD, 4, "setPenHueTo:"},
	{"-",0,4,NULL},
	{N_("change pen shade by %n"),				SSC_BT_CMD, 4, "changePenShadeBy:"},
	{N_("set pen shade to %n"),					SSC_BT_CMD, 4, "setPenShadeTo:"},
	{"-",0,4,NULL},
	{N_("change pen size by %n"),				SSC_BT_CMD, 4, "changePenSizeBy:"},
	{N_("set pen size to %n"),					SSC_BT_CMD, 4, "penSize:"},
	{"-",0,4,NULL},

	// stage pen
	{N_("clear"),								SSC_BT_CMD, 104, "clearPenTrails"},

	// triggers
	{N_("when @greenFlag clicked"),				SSC_BT_HAT, 5, "whenGreenFlag"},
	{N_("when %m.key key pressed"),				SSC_BT_HAT, 5, "whenKeyPressed"},
	{N_("when this sprite clicked"),			SSC_BT_HAT, 5, "whenClicked"},
	{N_("when backdrop switches to %m.backdrop"), SSC_BT_HAT, 5, "whenSceneStarts"},
	{"--",0,5,NULL},
	{N_("when %m.triggerSensor > %n"),			SSC_BT_HAT, 5, "whenSensorGreaterThan"},
	{"--",0,5,NULL},
	{N_("when I receive %m.broadcast"),			SSC_BT_HAT, 5, "whenIReceive"},
	{N_("broadcast %m.broadcast"),				SSC_BT_CMD, 5, "broadcast:"},
	{N_("broadcast %m.broadcast and wait"),		SSC_BT_CMD, 5, "doBroadcastAndWait"},

	// control - sprite
	{N_("wait %n secs"),						SSC_BT_CMD, 6, "wait:elapsed:from:"},
	{"-",0,6,NULL},
	{N_("repeat %n"),							SSC_BT_LOOP, 6, "doRepeat"},
	{N_("forever"),								SSC_BT_LOOP_FINAL,6, "doForever"},
	{"-",0,6,NULL},
	{N_("if %b then"),							SSC_BT_LOOP, 6, "doIf"},
	{N_("if %b then"),							SSC_BT_IFELSE, 6, "doIfElse"},
	{N_("wait until %b"),						SSC_BT_CMD, 6, "doWaitUntil"},
	{N_("repeat until %b"),						SSC_BT_LOOP, 6, "doUntil"},
	{"-",0,6,NULL},
	{N_("stop %m.stop"),						SSC_BT_FINAL_CMD, 6, "stopScripts"},
	{"-",0,6,NULL},
	{N_("when I start as a clone"),				SSC_BT_HAT, 6, "whenCloned"},
	{N_("create clone of %m.spriteOnly"),		SSC_BT_CMD, 6, "createCloneOf"},
	{N_("delete this clone"),					SSC_BT_FINAL_CMD, 6, "deleteClone"},
	{"-",0,6,NULL},

	// control - stage
	{N_("wait %n secs"),						SSC_BT_CMD, 106, "wait:elapsed:from:"},
	{"-",0,106,NULL},
	{N_("repeat %n"),							SSC_BT_LOOP, 106, "doRepeat"},
	{N_("forever"),								SSC_BT_LOOP_FINAL,106, "doForever"},
	{"-",0,106,NULL},
	{N_("if %b then"),							SSC_BT_LOOP, 106, "doIf"},
	{N_("if %b then"),							SSC_BT_IFELSE, 106, "doIfElse"},
	{N_("wait until %b"),						SSC_BT_CMD, 106, "doWaitUntil"},
	{N_("repeat until %b"),						SSC_BT_LOOP, 106, "doUntil"},
	{"-",0,106,NULL},
	{N_("stop %m.stop"),						SSC_BT_FINAL_CMD, 106, "stopScripts"},
	{"-",0,106,NULL},
	{N_("create clone of %m.spriteOnly"),		SSC_BT_CMD, 106, "createCloneOf"},

	// sensing
	{N_("touching %m.touching?"),				SSC_BT_BOOL, 7, "touching:"},
	{N_("touching color %c?"),					SSC_BT_BOOL, 7, "touchingColor:"},
	{N_("color %c is touching %c?"),			SSC_BT_BOOL, 7, "color:sees:"},
	{N_("distance to %m.spriteOrMouse"),		SSC_BT_NUM, 7, "distanceTo:"},
	{"-",0,7,NULL},
	{N_("ask %s and wait"),						SSC_BT_CMD, 7, "doAsk"},
	{N_("answer"),								SSC_BT_NUM, 7, "answer"},
	{"-",0,7,NULL},
	{N_("key %m.key pressed?"),					SSC_BT_BOOL, 7, "keyPressed:"},
	{N_("mouse down?"),							SSC_BT_BOOL, 7, "mousePressed"},
	{N_("mouse x"),								SSC_BT_NUM, 7, "mouseX"},
	{N_("mouse y"),								SSC_BT_NUM, 7, "mouseY"},
	{"-",0,7,NULL},
	{N_("loudness"),							SSC_BT_NUM, 7, "soundLevel"},
	{"-",0,7,NULL},
	{N_("video %m.videoMotionType on %m.stageOrThis"), SSC_BT_NUM, 7, "senseVideoMotion"},
	{N_("turn video %m.videoState"),			SSC_BT_CMD, 7, "setVideoState"},
	{N_("set video transparency to %n%"),		SSC_BT_CMD, 7, "setVideoTransparency"},
	{"-",0,7,NULL},
	{N_("timer"),								SSC_BT_NUM, 7, "timer"},
	{N_("reset timer"),							SSC_BT_CMD, 7, "timerReset"},
	{"-",0,7,NULL},
	{N_("%m.attribute of %m.spriteOrStage"),	SSC_BT_NUM, 7, "getAttribute:of:"},
	{"-",0,7,NULL},
	{N_("current %m.timeAndDate"), 				SSC_BT_NUM, 7, "timeAndDate"},
	{N_("days since 2000"), 					SSC_BT_NUM, 7, "timestamp"},
	{N_("username"),							SSC_BT_NUM, 7, "getUserName"},

	// stage sensing
	{N_("ask %s and wait"),						SSC_BT_CMD, 107, "doAsk"},
	{N_("answer"),								SSC_BT_NUM, 107, "answer"},
	{"-",0,107,NULL},
	{N_("key %m.key pressed?"),					SSC_BT_BOOL, 107, "keyPressed:"},
	{N_("mouse down?"),							SSC_BT_BOOL, 107, "mousePressed"},
	{N_("mouse x"),								SSC_BT_NUM, 107, "mouseX"},
	{N_("mouse y"),								SSC_BT_NUM, 107, "mouseY"},
	{"-",0,107,NULL},
	{N_("loudness"),							SSC_BT_NUM, 107, "soundLevel"},
	{"-",0,107,NULL},
	{N_("video %m.videoMotionType on %m.stageOrThis"), SSC_BT_NUM, 107, "senseVideoMotion"},
	{N_("turn video %m.videoState"),			SSC_BT_CMD, 107, "setVideoState"},
	{N_("set video transparency to %n%"),		SSC_BT_CMD, 107, "setVideoTransparency"},
	{"-",0,107,NULL},
	{N_("timer"),								SSC_BT_NUM, 107, "timer"},
	{N_("reset timer"),							SSC_BT_CMD, 107, "timerReset"},
	{"-",0,107,NULL},
	{N_("%m.attribute of %m.spriteOrStage"),	SSC_BT_NUM, 107, "getAttribute:of:"},
	{"-",0,107,NULL},
	{N_("current %m.timeAndDate"), 				SSC_BT_NUM, 107, "timeAndDate"},
	{N_("days since 2000"), 					SSC_BT_NUM, 107, "timestamp"},
	{N_("username"),							SSC_BT_NUM, 107, "getUserName"},

	// operators
	{N_("%n + %n"),								SSC_BT_NUM, 8, "+"},
	{N_("%n - %n"),								SSC_BT_NUM, 8, "-"},
	{N_("%n * %n"),								SSC_BT_NUM, 8, "*"},
	{N_("%n / %n"),								SSC_BT_NUM, 8, "/"},
	{"-",0,8,NULL},
	{N_("pick random %n to %n"),		SSC_BT_NUM, 8, "randomFrom:to:"},
	{"-",0,8,NULL},
	{N_("%s < %s"),								SSC_BT_BOOL, 8, "<"},
	{N_("%s = %s"),								SSC_BT_BOOL, 8, "="},
	{N_("%s > %s"),								SSC_BT_BOOL, 8, ">"},
	{"-",0,8,NULL},
	{N_("%b and %b"),							SSC_BT_BOOL, 8, "&"},
	{N_("%b or %b"),							SSC_BT_BOOL, 8, "|"},
	{N_("not %b"),								SSC_BT_BOOL, 8, "not"},
	{"-",0,8,NULL},
	{N_("join %s %s"),							SSC_BT_NUM, 8, "concatenate:with:"},
	{N_("letter %n of %s"),						SSC_BT_NUM, 8, "letter:of:"},
	{N_("length of %s"),						SSC_BT_NUM, 8, "stringLength:"},
	{"-",0,8,NULL},
	{N_("%n mod %n"),							SSC_BT_NUM, 8, "%"},
	{N_("round %n"),							SSC_BT_NUM, 8, "rounded"},
	{"-",0,8,NULL},
	{N_("%m.mathOp of %n"),						SSC_BT_NUM, 8, "computeFunction:of:"},

	// variables
	{N_("set %m.var to %s"),								SSC_BT_CMD, 9, "readVariable"},
	{N_("change %m.var by %n"),								SSC_BT_CMD, 9, "changeVar:by:"},
	{N_("show variable %m.var"),							SSC_BT_CMD, 9, "showVariable:"},
	{N_("hide variable %m.var"),							SSC_BT_CMD, 9, "hideVariable:"},

	// lists
	{N_("add %s to %m.list"),								SSC_BT_CMD, 12, "append:toList:"},
	{"-",0,12,NULL},
	{N_("delete %d.listDeleteItem of %m.list"),				SSC_BT_CMD, 12, "deleteLine:ofList:"},
	{N_("insert %s at %d.listItem of %m.list"),				SSC_BT_CMD, 12, "insert:at:ofList:"},
	{N_("replace item %d.listItem of %m.list with %s"),		SSC_BT_CMD, 12, "setLine:ofList:to:"},
	{"-",0,12,NULL},
	{N_("item %d.listItem of %m.list"),						SSC_BT_NUM, 12, "getLine:ofList:"},
	{N_("length of %m.list"),								SSC_BT_NUM, 12, "lineCountOfList:"},
	{N_("%m.list contains %s?"),								SSC_BT_BOOL, 12, "list:contains:"},
	{"-",0,12,NULL},
	{N_("show list %m.list"),								SSC_BT_CMD, 12, "showList:"},
	{N_("hide list %m.list"),								SSC_BT_CMD, 12, "hideList:"},

	// obsolete blocks from Scratch 1.4 that may be used in older projects
	{N_("play drum %n for %n beats"),			SSC_BT_CMD, 98, "drum:duration:elapsed:from:"}, // Scratch 1.4 MIDI drum
	{N_("set instrument to %n"),				SSC_BT_CMD, 98, "midiInstrument:"},
	{N_("loud?"),								SSC_BT_BOOL, 98, "isLoud"},

	// obsolete blocks from Scratch 1.4 that are converted to new forms (so should never appear):
	{N_("abs %n"),								SSC_BT_NUM, 98, "abs"},
	{N_("sqrt %n"),								SSC_BT_NUM, 98, "sqrt"},
	{N_("stop script"),							SSC_BT_FINAL_CMD, 98, "doReturn"},
	{N_("stop all"),							SSC_BT_FINAL_CMD, 98, "stopAll"},
	{N_("switch to background %m.costume"),		SSC_BT_CMD, 98, "showBackground:"},
	{N_("next background"),						SSC_BT_CMD, 98, "nextBackground"},
	{N_("forever if %b"),						SSC_BT_LOOP_FINAL,98, "doForeverIf"},

	// testing and experimental control prims
	{N_("noop"),								SSC_BT_NUM, 99, "COUNT"},
	{N_("counter"),								SSC_BT_NUM, 99, "COUNT"},
	{N_("clear counter"),						SSC_BT_CMD, 99, "CLR_COUNT"},
	{N_("incr counter"),						SSC_BT_CMD, 99, "INCR_COUNT"},
	{N_("for each %m.varName in %s"),			SSC_BT_LOOP, 99, "doForLoop"},
	{N_("while %b"),							SSC_BT_LOOP, 99, "doWhile"},
	{N_("all at once"),							SSC_BT_LOOP, 99, "warpSpeed"},

	// stage motion (scrolling)
	{N_("scroll right %n"),						SSC_BT_CMD, 99, "scrollRight"},
	{N_("scroll up %n"),						SSC_BT_CMD, 99, "scrollUp"},
	{N_("align scene %m.scrollAlign"),			SSC_BT_CMD, 99, "scrollAlign"},
	{N_("x scroll"),							SSC_BT_NUM, 99, "xScroll"},
	{N_("y scroll"),							SSC_BT_NUM, 99, "yScroll"},

	// other obsolete blocks from alpha/beta
	{N_("hide all sprites"),					SSC_BT_CMD, 99, "hideAll"},
	{N_("user id"),								SSC_BT_NUM, 99, "getUserId"},

	//返回式函数

	{N_("return %s"),							SSC_BT_FINAL_CMD, 10, "funReturn"},

	// SteveBlocks
	{"--",0,13,NULL},
	{N_("color on x:%n y:%n"),								SSC_BT_NUM, 13, "getColorOn"},

	{"--",0,13,NULL},
	{N_("play sound %m.sound on %n sec"),					SSC_BT_CMD, 13, "playSoundOnPos"},
	{N_("play sound %m.sound on %n sec until done"),		SSC_BT_CMD, 13, "doPlaySoundOnPosAndWait"},
	{"--",0,13,NULL},
	//{N_("set pen shape to %m.penShape"),					SSC_BT_CMD, 13, "setPenShape"},
	{N_("print %s on X:%n Y:%n"),							SSC_BT_CMD, 13, "printText"},
	{N_("set print font to %m.fontName"),					SSC_BT_CMD, 13, "setFont"},
	{N_("set print font color to %c"),						SSC_BT_CMD, 13, "setFontColor"},
	{N_("set print font size to %n"),						SSC_BT_CMD, 13, "setFontSize"},
	{N_("set print font bold is %m.boolean"),				SSC_BT_CMD, 13, "setFontBold"},
	{N_("set print font italic is %m.boolean"),				SSC_BT_CMD, 13, "setFontItalic"},
	{N_("set print font underline is %m.boolean"),			SSC_BT_CMD, 13, "setFontUnderline"},

	{"--",0,13,NULL},
	{N_("rotate axis x by %n"),								SSC_BT_CMD, 13, "addRotX"},
	{N_("rotate axis y by %n"),								SSC_BT_CMD, 13, "addRotY"},
	{N_("rotate axis z by %n"),								SSC_BT_CMD, 13, "addRotZ"},
	{N_("set axis x to %n"),								SSC_BT_CMD, 13, "setRotX"},
	{N_("set axis y to %n"),								SSC_BT_CMD, 13, "setRotY"},
	{N_("set axis z to %n"),								SSC_BT_CMD, 13, "setRotZ"},
	{N_("axis x"),											SSC_BT_NUM, 13, "rotX"},
	{N_("axis y"),											SSC_BT_NUM, 13, "rotY"},
	{N_("axis z"),											SSC_BT_NUM, 13, "rotZ"},
	{"--",0,13,NULL},
	{N_("set resolution to x:%n y:%n"),						SSC_BT_CMD, 13, "setResolution"},
	{"--",0,13,NULL},
	{N_("set local data %s to %s"),							SSC_BT_CMD, 13, "setLocalData"},
	{N_("get local data from %s"),							SSC_BT_NUM, 13, "getLocalData"},
	{"--",0,13,NULL},
	{N_("%m.hideOrShow all %m.valueOrList in %m.spriteAndStage"),SSC_BT_CMD, 13, "setAllValueListVisible"},
	{"--",0,13,NULL},

	// KindForNoobs

	{N_("%s == %s"),										SSC_BT_BOOL, 14, "=="},
	{N_("if %b then %s else %s"),							SSC_BT_NUM, 14, "ifThenElse"},
	{"--",0,14,NULL},

	{N_("upper %s"),										SSC_BT_NUM, 14, "strToUpper"},
	{N_("lower %s"),										SSC_BT_NUM, 14, "strToLower"},
	{N_("invert %s"),										SSC_BT_NUM, 14, "invertStr"},
	{"--",0,14,NULL},

	{N_("get unicode of %n to text"),						SSC_BT_NUM, 14, "getUnicodeToText"},
	{N_("get text of %s to unicode"),						SSC_BT_NUM, 14, "getTextToUnicode"},
	{N_("get text from %n to %n in %s"),					SSC_BT_NUM, 14, "getStrFromTo"},
	{N_("%n position of %s contain %s"),					SSC_BT_NUM, 14, "posContainStr"},
	{"--",0,14,NULL},

	{N_("将二进制的 %s 转换为十进制"),					SSC_BT_NUM, 14, "binToDec"},
	{N_("将二进制的 %s 转换为十六进制"),					SSC_BT_NUM, 14, "binToHex"},
	{N_("将二进制的 %s 转换为八进制"),					SSC_BT_NUM, 14, "binToOct"},

	{N_("use %c to draw a square on x:%n y:%n width:%n height:%n"),	SSC_BT_CMD, 14, "drawRect"},

	{"--",0,14,NULL},
	{N_("hide all sprite %m.boolean"),						SSC_BT_CMD, 14, "setAllSpriteVisible"},
	{NULL,NULL,14,NULL}
};

ssc_cReg* ssc_specs_categories_get()
{
	return ssc_specs_categories;
}

ssc_cmdReg* ssc_specs_commands_get()
{
	return ssc_specs_commands;
}

GdkRGBA* ssc_specs_get_color_by_category_name(gchar* name)
{
	gint i = 0;
	textdomain("specs");
	while(ssc_specs_categories[i].num != -1)
	{
		if(!strcmp(ssc_specs_categories[i].name,name) ||
			!strcmp(_(ssc_specs_categories[i].name),name)
			)
		{
			if(ssc_specs_categories[i].color)
			{
				return ssc_specs_categories[i].color;
			}else{
				ssc_specs_categories[i].color = ssc_libs_g_malloc(sizeof(GdkRGBA));
				gdk_rgba_parse(ssc_specs_categories[i].color,ssc_specs_categories[i].colorStr);
				return ssc_specs_categories[i].color;
			}
		}
		i++;
	}
	return NULL;
}

GdkRGBA* ssc_specs_get_color_by_category_id(gint* id)
{
	gint i = 0;
	while(ssc_specs_categories[i].num != -1)
	{
		if(ssc_specs_categories[i].num == id)
		{
			if(ssc_specs_categories[i].color)// 如果已经解析过一次颜色的话就直接取颜色值节省时间
			{
				return ssc_specs_categories[i].color;
			}else{
				ssc_specs_categories[i].color = ssc_libs_g_malloc(sizeof(GdkRGBA));
				gdk_rgba_parse(ssc_specs_categories[i].color,ssc_specs_categories[i].colorStr);
				//print("C %s :{%d,%d,%d,%d}\n",ssc_specs_categories[i].name,ssc_specs_categories[i].color->red,ssc_specs_categories[i].color->green,ssc_specs_categories[i].color->blue,ssc_specs_categories[i].color->alpha);
				return ssc_specs_categories[i].color;
			}
		}
		i++;
	}
	return -1;
}

gint ssc_specs_get_category_by_block_spec(gchar* spec)
{
	gint i = 0;
	while(ssc_specs_commands[i].spec!=0)
	{
		//print("%s : %s\n",ssc_specs_commands[i].spec,spec);
		if(!strcmp(ssc_specs_commands[i].spec,spec) ||
			!strcmp(_(ssc_specs_commands[i].spec),spec)
			)
		{
			return ssc_specs_commands[i].cate;
		}
		i++;
	}
	return NULL;
}
