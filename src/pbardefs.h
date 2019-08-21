#ifndef __PBARDEFS_INCLUDED__
#define __PBARDEFS_INCLUDED__

/*******************************************************/
/* There are 2 simple ways to make a colormap,
   both of which are used in the header.
   Look in pbar.c to see how the colormaps are
   created in the AFNI GUI.

    * N byte triples -> PBAR_define_bigmap()
      Here, you define a char array, one giant
      string, using spaces to delimit the N+1
      sub-strings:
        Name #rrggbb #rrggbb ... (N of these)
      where the N #rrggbb values each have six
      hex digits defining the colors. In this
      usage, the number N of defining colors
      is inferred from the number of sub-strings
      in the big input string.
      The CytoArch_ROI_i256 map is a sample.

    * N float triples -> PBAR_define_bigmap_float()
      Here, you define a float array, length 3*N,
      which for each color contains the 3 RGB values
      (range = 0..1), in the order
        R0 G0 B0 R1 G1 B1 R2 G2 B2 ...
      In this usage, the number N of defining colors
      must be supplied explicitly, as is the colormap
      name to be used in menus.
      The googleturbo map is a sample; e.g., the
      last color triple there is
         0.47960, 0.01583, 0.01055
      which is mostly Red. The number N and the name
      are provided by
        #define      googleturbo_num 256
        static char *googleturbo_name = "GoogleTurbo" ;
      which are passed to PBAR_define_bigmap_float().

   Internally, a colormap is 256 colors long
   (unless option '-XXXnpane' is provided on the AFNI
   GUI command line.). Providing fewer colors will mean
   that the extra colors are provided by interpolation
   in the array of RGB values provided.

   There are more complicated ways to make a colormap.
   See pbar.c (at the risk of your sanity).
*//*****************************************************/

/* ZSS: New 256-color maps.
   Each new color map is added with
   a call to PBAR_define_bigmap in pbar.c
*/

/* Color map for The Eickhoff and Zilles
   Cytoarchitectonic data AllAreas_v12

  see matlab/MakeCytoArchColMaps.m
*/
static char CYTOARCH_ROI_256_CMD[] = {
      "CytoArch_ROI_i256 "
      "#84392e #018f67 #776b1b #01d9d4 #9f35b8 "
      "#f7d202 #2100cf #d494f6 #bbfa2d #fd2d74 "
      "#90c648 #c4516e #fe28fd #a83d26 #4fda69 "
      "#40fcf8 #c4589f #27abf3 #610051 #49f8c0 "
      "#ad185d #68f88d #d80491 #d92918 #2b649d "
      "#65bbea #772e83 #fed039 #0591b2 #ed2b3e "
      "#67a84b #cb7941 #7a2eb0 #39af94 #57fa28 "
      "#fb7dfd #a46b42 #13e94c #4b70f0 #c8cf33 "
      "#02e79a #fcae11 #96d7fb #42358b #0009fd "
      "#ff2bcf #9d9909 #173472 #fe7c31 #3780c8 "
      "#1041fe #f0d260 #a19349 #45ff8a #fd9376 "
      "#cf3fcc #c3c866 #059489 #3cfe59 #ff0091 "
      "#fbb3a1 #c8f104 #d92a70 #86ef42 #7b02ea "
      "#fde693 #b408b2 #1b52d4 #f687cd #8257b9 "
      "#88100b #fa03cb #e85783 #045602 #7d97fa "
      "#8cfe76 #1608a9 #fdff01 #ff56b9 #0d359a "
      "#b41335 #7b07ab #3dc0c5 #feab3d #6fc9af "
      "#0afdf9 #b9f760 #4cc50f #c067fe #fffb5f "
      "#df7e05 #ba00de #3d954b #c636f6 #05b7c2 "
      "#ac3d02 #0d7e3d #534fb4 #ac7119 #ab0a85 "
      "#0667a5 #17b80f #494be9 #860b3b #85c323 "
      "#6ddedd #3d888c #d5956d #378307 #390872 "
      "#8463ff #24f0c6 #d1b100 #02fc73 #90ffa8 "
      "#01c6fc #fd1017 #4407f2 #9b4450 #03b24b "
      "#a0428e #02bf89 #4d96ff #79490c #461ab6 "
      "#43d344 #b06dc9 #df4e04 #83d16f #04f025 "
      "#a2fee4 #e80153 #ffa6f8 #96f718 #5e83c0 "
      "#eb02f9 #bf0005 #cfa736 #0a7fdf #f685a0 "
      "#000a7a #e12ba0 #046372 #d1eb91 #740377 "
      "#39d6fc #708e1f #acb0fd #fd52fa #01840a "
      "#0626d6 #5c0a08 #e3f92f #49ff00 #3ed78e "
      "#872cde #df5146 #b3b3b3 #b1b1b1 #afafaf "
      "#aeaeae #acacac #ababab #a9a9a9 #a8a8a8 "
      "#a6a6a6 #a4a4a4 #a3a3a3 #a1a1a1 #a0a0a0 "
      "#9e9e9e #9d9d9d #9b9b9b #9a9a9a #989898 "
      "#969696 #959595 #939393 #929292 #909090 "
      "#8f8f8f #8d8d8d #8b8b8b #8a8a8a #888888 "
      "#878787 #858585 #848484 #828282 #818181 "
      "#7f7f7f #7d7d7d #7c7c7c #7a7a7a #797979 "
      "#777777 #767676 #747474 #727272 #717171 "
      "#6f6f6f #6e6e6e #6c6c6c #6b6b6b #696969 "
      "#686868 #666666 #646464 #636363 #616161 "
      "#606060 #5e5e5e #5d5d5d #5b5b5b #5a5a5a "
      "#585858 #565656 #555555 #535353 #525252 "
      "#505050 #4f4f4f #4d4d4d #4b4b4b #4a4a4a "
      "#484848 #474747 #454545 #444444 #424242 "
      "#414141 #3f3f3f #3d3d3d #3c3c3c #3a3a3a "
      "#393939 #373737 #363636 #343434 #323232 "
      "#313131 #2f2f2f #2e2e2e #2c2c2c #2b2b2b "
      "#292929 #282828 #262626 #242424 #232323 "
      "#212121 #202020 #1e1e1e #1d1d1d #1b1b1b "
      "#1a1a1a "
};
static char CYTOARCH_ROI_256_GAP_CMD[] = {
      "CytoArch_ROI_i256_gap "
      "#84392e #018f67 #776b1b #01d9d4 #9f35b8 "
      "#f7d202 #2100cf #d494f6 #bbfa2d #fd2d74 "
      "#90c648 #c4516e #fe28fd #a83d26 #4fda69 "
      "#40fcf8 #c4589f #27abf3 #610051 #49f8c0 "
      "#ad185d #68f88d #d80491 #d92918 #2b649d "
      "#65bbea #772e83 #fed039 #0591b2 #ed2b3e "
      "#67a84b #cb7941 #7a2eb0 #39af94 #57fa28 "
      "#fb7dfd #a46b42 #13e94c #4b70f0 #c8cf33 "
      "#02e79a #fcae11 #96d7fb #42358b #0009fd "
      "#ff2bcf #9d9909 #173472 #fe7c31 #3780c8 "
      "#1041fe #f0d260 #a19349 #45ff8a #fd9376 "
      "#cf3fcc #c3c866 #059489 #3cfe59 #ff0091 "
      "#fbb3a1 #c8f104 #d92a70 #86ef42 #7b02ea "
      "#fde693 #b408b2 #1b52d4 #f687cd #8257b9 "
      "#88100b #fa03cb #e85783 #045602 #7d97fa "
      "#8cfe76 #1608a9 #fdff01 #ff56b9 #0d359a "
      "#b41335 #7b07ab #3dc0c5 #feab3d #6fc9af "
      "#0afdf9 #b9f760 #4cc50f #c067fe #fffb5f "
      "#df7e05 #ba00de #3d954b #c636f6 #05b7c2 "
      "#ac3d02 #0d7e3d #534fb4 #ac7119 #ab0a85 "
      "#0667a5 #17b80f #494be9 #860b3b #85c323 "
      "#6ddedd #3d888c #d5956d #378307 #390872 "
      "#8463ff #24f0c6 #d1b100 #02fc73 #90ffa8 "
      "#01c6fc #fd1017 #4407f2 #9b4450 #03b24b "
      "#a0428e #02bf89 #4d96ff #79490c #461ab6 "
      "#43d344 #b06dc9 #df4e04 #83d16f #04f025 "
      "#a2fee4 #e80153 #ffa6f8 #96f718 #5e83c0 "
      "#eb02f9 #bf0005 #cfa736 #0a7fdf #f685a0 "
      "#000a7a #e12ba0 #046372 #d1eb91 #740377 "
      "#39d6fc #708e1f #acb0fd #fd52fa #01840a "
      "#0626d6 #5c0a08 #e3f92f #49ff00 #3ed78e "
      "#872cde #df5146 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 #000000 #000000 #000000 #000000 "
      "#000000 "
};
/* While we're at it, some maps for ROI drawing
   see matlab/MakeROIColMaps.m
*/
static char ROI_256_CMD[] = {
      "ROI_i256 "
      "#41a2b0 #0a32b6 #df70f8 #78f525 #d80475 "
      "#cf7c23 #fbb060 #5df345 #fc3820 #d97d98 "
      "#15b76c #fd8b14 #83b6ed #a544fa #adbd02 "
      "#8f0459 #90e18d #d90ad8 #56146f #59dffb "
      "#3f07d3 #fe2e95 #ac1f0a #01c12c #8ee1d6 "
      "#6bfa67 #2adb1f #4e29fb #dd0203 #086420 "
      "#de53fc #47b5f6 #7f2261 #7e9601 #a748db "
      "#21dfa7 #68a8c5 #02f804 #d05024 #d8fd74 "
      "#0007ce #fb7576 #07d66a #69022b #02f8cd "
      "#650acc #f80372 #be3b45 #fdb37f #3ea0cd "
      "#ff5a57 #e0f450 #a69229 #2504fb #6ecf91 "
      "#8a04cc #2d7dfd #22ffa1 #0660f7 #256401 "
      "#450195 #c9d009 #2b822b #7a33fd #c77461 "
      "#25b548 #adec88 #c235a1 #67f4ab #d305b5 "
      "#4ba51a #9f1cff #60b56c #045650 #ef60da "
      "#622ad6 #6efee7 #c101ff #fd8654 #a6c21f "
      "#28d66d #ff5c04 #3029da #82cc03 #8c89d9 "
      "#f35624 #65cf44 #090355 #b18ff1 #dc0327 "
      "#8564dd #20ef02 #04a4f0 #515e02 #3041ad "
      "#30fb2a #d283ce #6df405 #3cad6e #84392e "
      "#018f67 #776b1b #01d9d4 #9f35b8 #f7d202 "
      "#2100cf #d494f6 #bbfa2d #fd2d74 #90c648 "
      "#c4516e #fe28fd #a83d26 #4fda69 #40fcf8 "
      "#c4589f #27abf3 #610051 #49f8c0 #ad185d "
      "#68f88d #d80491 #d92918 #2b649d #65bbea "
      "#772e83 #fed039 #0591b2 #ed2b3e #67a84b "
      "#cb7941 #7a2eb0 #39af94 #57fa28 #fb7dfd "
      "#a46b42 #13e94c #4b70f0 #c8cf33 #02e79a "
      "#fcae11 #96d7fb #42358b #0009fd #ff2bcf "
      "#9d9909 #173472 #fe7c31 #3780c8 #1041fe "
      "#f0d260 #a19349 #45ff8a #fd9376 #cf3fcc "
      "#c3c866 #059489 #3cfe59 #ff0091 #fbb3a1 "
      "#c8f104 #d92a70 #86ef42 #7b02ea #fde693 "
      "#b408b2 #1b52d4 #f687cd #8257b9 #88100b "
      "#fa03cb #e85783 #045602 #7d97fa #8cfe76 "
      "#1608a9 #fdff01 #ff56b9 #0d359a #b41335 "
      "#7b07ab #3dc0c5 #feab3d #6fc9af #0afdf9 "
      "#b9f760 #4cc50f #c067fe #fffb5f #df7e05 "
      "#ba00de #3d954b #c636f6 #05b7c2 #ac3d02 "
      "#0d7e3d #534fb4 #ac7119 #ab0a85 #0667a5 "
      "#17b80f #494be9 #860b3b #85c323 #6ddedd "
      "#3d888c #d5956d #378307 #390872 #8463ff "
      "#24f0c6 #d1b100 #02fc73 #90ffa8 #01c6fc "
      "#fd1017 #4407f2 #9b4450 #03b24b #a0428e "
      "#02bf89 #4d96ff #79490c #461ab6 #43d344 "
      "#b06dc9 #df4e04 #83d16f #04f025 #a2fee4 "
      "#e80153 #ffa6f8 #96f718 #5e83c0 #eb02f9 "
      "#bf0005 #cfa736 #0a7fdf #f685a0 #000a7a "
      "#e12ba0 #046372 #d1eb91 #740377 #39d6fc "
      "#708e1f #acb0fd #fd52fa #01840a #0626d6 "
      "#5c0a08 #e3f92f #49ff00 #3ed78e #872cde "
      "#df5146 "
};

static char ROI_128_CMD[] = {
      "ROI_i128 "
      "#ed2b3e #67a84b #cb7941 #7a2eb0 #39af94 "
      "#57fa28 #fb7dfd #a46b42 #13e94c #4b70f0 "
      "#c8cf33 #02e79a #fcae11 #96d7fb #42358b "
      "#0009fd #ff2bcf #9d9909 #173472 #fe7c31 "
      "#3780c8 #1041fe #f0d260 #a19349 #45ff8a "
      "#fd9376 #cf3fcc #c3c866 #059489 #3cfe59 "
      "#ff0091 #fbb3a1 #c8f104 #d92a70 #86ef42 "
      "#7b02ea #fde693 #b408b2 #1b52d4 #f687cd "
      "#8257b9 #88100b #fa03cb #e85783 #045602 "
      "#7d97fa #8cfe76 #1608a9 #fdff01 #ff56b9 "
      "#0d359a #b41335 #7b07ab #3dc0c5 #feab3d "
      "#6fc9af #0afdf9 #b9f760 #4cc50f #c067fe "
      "#fffb5f #df7e05 #ba00de #3d954b #c636f6 "
      "#05b7c2 #ac3d02 #0d7e3d #534fb4 #ac7119 "
      "#ab0a85 #0667a5 #17b80f #494be9 #860b3b "
      "#85c323 #6ddedd #3d888c #d5956d #378307 "
      "#390872 #8463ff #24f0c6 #d1b100 #02fc73 "
      "#90ffa8 #01c6fc #fd1017 #4407f2 #9b4450 "
      "#03b24b #a0428e #02bf89 #4d96ff #79490c "
      "#461ab6 #43d344 #b06dc9 #df4e04 #83d16f "
      "#04f025 #a2fee4 #e80153 #ffa6f8 #96f718 "
      "#5e83c0 #eb02f9 #bf0005 #cfa736 #0a7fdf "
      "#f685a0 #000a7a #e12ba0 #046372 #d1eb91 "
      "#740377 #39d6fc #708e1f #acb0fd #fd52fa "
      "#01840a #0626d6 #5c0a08 #e3f92f #49ff00 "
      "#3ed78e #872cde #df5146 "
};
static char ROI_128_256_CMD[] = {
      "ROI_i128 "
      "#ed2b3e #ed2b3e #67a84b #67a84b #cb7941 "
      "#cb7941 #7a2eb0 #7a2eb0 #39af94 #39af94 "
      "#57fa28 #57fa28 #fb7dfd #fb7dfd #a46b42 "
      "#a46b42 #13e94c #13e94c #4b70f0 #4b70f0 "
      "#c8cf33 #c8cf33 #02e79a #02e79a #fcae11 "
      "#fcae11 #96d7fb #96d7fb #42358b #42358b "
      "#0009fd #0009fd #ff2bcf #ff2bcf #9d9909 "
      "#9d9909 #173472 #173472 #fe7c31 #fe7c31 "
      "#3780c8 #3780c8 #1041fe #1041fe #f0d260 "
      "#f0d260 #a19349 #a19349 #45ff8a #45ff8a "
      "#fd9376 #fd9376 #cf3fcc #cf3fcc #c3c866 "
      "#c3c866 #059489 #059489 #3cfe59 #3cfe59 "
      "#ff0091 #ff0091 #fbb3a1 #fbb3a1 #c8f104 "
      "#c8f104 #d92a70 #d92a70 #86ef42 #86ef42 "
      "#7b02ea #7b02ea #fde693 #fde693 #b408b2 "
      "#b408b2 #1b52d4 #1b52d4 #f687cd #f687cd "
      "#8257b9 #8257b9 #88100b #88100b #fa03cb "
      "#fa03cb #e85783 #e85783 #045602 #045602 "
      "#7d97fa #7d97fa #8cfe76 #8cfe76 #1608a9 "
      "#1608a9 #fdff01 #fdff01 #ff56b9 #ff56b9 "
      "#0d359a #0d359a #b41335 #b41335 #7b07ab "
      "#7b07ab #3dc0c5 #3dc0c5 #feab3d #feab3d "
      "#6fc9af #6fc9af #0afdf9 #0afdf9 #b9f760 "
      "#b9f760 #4cc50f #4cc50f #c067fe #c067fe "
      "#fffb5f #fffb5f #df7e05 #df7e05 #ba00de "
      "#ba00de #3d954b #3d954b #c636f6 #c636f6 "
      "#05b7c2 #05b7c2 #ac3d02 #ac3d02 #0d7e3d "
      "#0d7e3d #534fb4 #534fb4 #ac7119 #ac7119 "
      "#ab0a85 #ab0a85 #0667a5 #0667a5 #17b80f "
      "#17b80f #494be9 #494be9 #860b3b #860b3b "
      "#85c323 #85c323 #6ddedd #6ddedd #3d888c "
      "#3d888c #d5956d #d5956d #378307 #378307 "
      "#390872 #390872 #8463ff #8463ff #24f0c6 "
      "#24f0c6 #d1b100 #d1b100 #02fc73 #02fc73 "
      "#90ffa8 #90ffa8 #01c6fc #01c6fc #fd1017 "
      "#fd1017 #4407f2 #4407f2 #9b4450 #9b4450 "
      "#03b24b #03b24b #a0428e #a0428e #02bf89 "
      "#02bf89 #4d96ff #4d96ff #79490c #79490c "
      "#461ab6 #461ab6 #43d344 #43d344 #b06dc9 "
      "#b06dc9 #df4e04 #df4e04 #83d16f #83d16f "
      "#04f025 #04f025 #a2fee4 #a2fee4 #e80153 "
      "#e80153 #ffa6f8 #ffa6f8 #96f718 #96f718 "
      "#5e83c0 #5e83c0 #eb02f9 #eb02f9 #bf0005 "
      "#bf0005 #cfa736 #cfa736 #0a7fdf #0a7fdf "
      "#f685a0 #f685a0 #000a7a #000a7a #e12ba0 "
      "#e12ba0 #046372 #046372 #d1eb91 #d1eb91 "
      "#740377 #740377 #39d6fc #39d6fc #708e1f "
      "#708e1f #acb0fd #acb0fd #fd52fa #fd52fa "
      "#01840a #01840a #0626d6 #0626d6 #5c0a08 "
      "#5c0a08 #e3f92f #e3f92f #49ff00 #49ff00 "
      "#3ed78e #3ed78e #872cde #872cde #df5146 "
      "#df5146 "
};

static char ROI_64_CMD[] = {
      "ROI_i64 "
      "#c636f6 #05b7c2 #ac3d02 #0d7e3d #534fb4 "
      "#ac7119 #ab0a85 #0667a5 #17b80f #494be9 "
      "#860b3b #85c323 #6ddedd #3d888c #d5956d "
      "#378307 #390872 #8463ff #24f0c6 #d1b100 "
      "#02fc73 #90ffa8 #01c6fc #fd1017 #4407f2 "
      "#9b4450 #03b24b #a0428e #02bf89 #4d96ff "
      "#79490c #461ab6 #43d344 #b06dc9 #df4e04 "
      "#83d16f #04f025 #a2fee4 #e80153 #ffa6f8 "
      "#96f718 #5e83c0 #eb02f9 #bf0005 #cfa736 "
      "#0a7fdf #f685a0 #000a7a #e12ba0 #046372 "
      "#d1eb91 #740377 #39d6fc #708e1f #acb0fd "
      "#fd52fa #01840a #0626d6 #5c0a08 #e3f92f "
      "#49ff00 #3ed78e #872cde #df5146 "
};
static char ROI_64_256_CMD[] = {
      "ROI_i64 "
      "#c636f6 #c636f6 #c636f6 #c636f6 #05b7c2 "
      "#05b7c2 #05b7c2 #05b7c2 #ac3d02 #ac3d02 "
      "#ac3d02 #ac3d02 #0d7e3d #0d7e3d #0d7e3d "
      "#0d7e3d #534fb4 #534fb4 #534fb4 #534fb4 "
      "#ac7119 #ac7119 #ac7119 #ac7119 #ab0a85 "
      "#ab0a85 #ab0a85 #ab0a85 #0667a5 #0667a5 "
      "#0667a5 #0667a5 #17b80f #17b80f #17b80f "
      "#17b80f #494be9 #494be9 #494be9 #494be9 "
      "#860b3b #860b3b #860b3b #860b3b #85c323 "
      "#85c323 #85c323 #85c323 #6ddedd #6ddedd "
      "#6ddedd #6ddedd #3d888c #3d888c #3d888c "
      "#3d888c #d5956d #d5956d #d5956d #d5956d "
      "#378307 #378307 #378307 #378307 #390872 "
      "#390872 #390872 #390872 #8463ff #8463ff "
      "#8463ff #8463ff #24f0c6 #24f0c6 #24f0c6 "
      "#24f0c6 #d1b100 #d1b100 #d1b100 #d1b100 "
      "#02fc73 #02fc73 #02fc73 #02fc73 #90ffa8 "
      "#90ffa8 #90ffa8 #90ffa8 #01c6fc #01c6fc "
      "#01c6fc #01c6fc #fd1017 #fd1017 #fd1017 "
      "#fd1017 #4407f2 #4407f2 #4407f2 #4407f2 "
      "#9b4450 #9b4450 #9b4450 #9b4450 #03b24b "
      "#03b24b #03b24b #03b24b #a0428e #a0428e "
      "#a0428e #a0428e #02bf89 #02bf89 #02bf89 "
      "#02bf89 #4d96ff #4d96ff #4d96ff #4d96ff "
      "#79490c #79490c #79490c #79490c #461ab6 "
      "#461ab6 #461ab6 #461ab6 #43d344 #43d344 "
      "#43d344 #43d344 #b06dc9 #b06dc9 #b06dc9 "
      "#b06dc9 #df4e04 #df4e04 #df4e04 #df4e04 "
      "#83d16f #83d16f #83d16f #83d16f #04f025 "
      "#04f025 #04f025 #04f025 #a2fee4 #a2fee4 "
      "#a2fee4 #a2fee4 #e80153 #e80153 #e80153 "
      "#e80153 #ffa6f8 #ffa6f8 #ffa6f8 #ffa6f8 "
      "#96f718 #96f718 #96f718 #96f718 #5e83c0 "
      "#5e83c0 #5e83c0 #5e83c0 #eb02f9 #eb02f9 "
      "#eb02f9 #eb02f9 #bf0005 #bf0005 #bf0005 "
      "#bf0005 #cfa736 #cfa736 #cfa736 #cfa736 "
      "#0a7fdf #0a7fdf #0a7fdf #0a7fdf #f685a0 "
      "#f685a0 #f685a0 #f685a0 #000a7a #000a7a "
      "#000a7a #000a7a #e12ba0 #e12ba0 #e12ba0 "
      "#e12ba0 #046372 #046372 #046372 #046372 "
      "#d1eb91 #d1eb91 #d1eb91 #d1eb91 #740377 "
      "#740377 #740377 #740377 #39d6fc #39d6fc "
      "#39d6fc #39d6fc #708e1f #708e1f #708e1f "
      "#708e1f #acb0fd #acb0fd #acb0fd #acb0fd "
      "#fd52fa #fd52fa #fd52fa #fd52fa #01840a "
      "#01840a #01840a #01840a #0626d6 #0626d6 "
      "#0626d6 #0626d6 #5c0a08 #5c0a08 #5c0a08 "
      "#5c0a08 #e3f92f #e3f92f #e3f92f #e3f92f "
      "#49ff00 #49ff00 #49ff00 #49ff00 #3ed78e "
      "#3ed78e #3ed78e #3ed78e #872cde #872cde "
      "#872cde #872cde #df5146 #df5146 #df5146 "
      "#df5146 "
};

static char ROI_32_CMD[] = {
      "ROI_i32 "
      "#43d344 #b06dc9 #df4e04 #83d16f #04f025 "
      "#a2fee4 #e80153 #ffa6f8 #96f718 #5e83c0 "
      "#eb02f9 #bf0005 #cfa736 #0a7fdf #f685a0 "
      "#000a7a #e12ba0 #046372 #d1eb91 #740377 "
      "#39d6fc #708e1f #acb0fd #fd52fa #01840a "
      "#0626d6 #5c0a08 #e3f92f #49ff00 #3ed78e "
      "#872cde #df5146 "
};

static char ROI_32_256_CMD[] = {
      "ROI_i32 "
      "#43d344 #43d344 #43d344 #43d344 #43d344 "
      "#43d344 #43d344 #43d344 #b06dc9 #b06dc9 "
      "#b06dc9 #b06dc9 #b06dc9 #b06dc9 #b06dc9 "
      "#b06dc9 #df4e04 #df4e04 #df4e04 #df4e04 "
      "#df4e04 #df4e04 #df4e04 #df4e04 #83d16f "
      "#83d16f #83d16f #83d16f #83d16f #83d16f "
      "#83d16f #83d16f #04f025 #04f025 #04f025 "
      "#04f025 #04f025 #04f025 #04f025 #04f025 "
      "#a2fee4 #a2fee4 #a2fee4 #a2fee4 #a2fee4 "
      "#a2fee4 #a2fee4 #a2fee4 #e80153 #e80153 "
      "#e80153 #e80153 #e80153 #e80153 #e80153 "
      "#e80153 #ffa6f8 #ffa6f8 #ffa6f8 #ffa6f8 "
      "#ffa6f8 #ffa6f8 #ffa6f8 #ffa6f8 #96f718 "
      "#96f718 #96f718 #96f718 #96f718 #96f718 "
      "#96f718 #96f718 #5e83c0 #5e83c0 #5e83c0 "
      "#5e83c0 #5e83c0 #5e83c0 #5e83c0 #5e83c0 "
      "#eb02f9 #eb02f9 #eb02f9 #eb02f9 #eb02f9 "
      "#eb02f9 #eb02f9 #eb02f9 #bf0005 #bf0005 "
      "#bf0005 #bf0005 #bf0005 #bf0005 #bf0005 "
      "#bf0005 #cfa736 #cfa736 #cfa736 #cfa736 "
      "#cfa736 #cfa736 #cfa736 #cfa736 #0a7fdf "
      "#0a7fdf #0a7fdf #0a7fdf #0a7fdf #0a7fdf "
      "#0a7fdf #0a7fdf #f685a0 #f685a0 #f685a0 "
      "#f685a0 #f685a0 #f685a0 #f685a0 #f685a0 "
      "#000a7a #000a7a #000a7a #000a7a #000a7a "
      "#000a7a #000a7a #000a7a #e12ba0 #e12ba0 "
      "#e12ba0 #e12ba0 #e12ba0 #e12ba0 #e12ba0 "
      "#e12ba0 #046372 #046372 #046372 #046372 "
      "#046372 #046372 #046372 #046372 #d1eb91 "
      "#d1eb91 #d1eb91 #d1eb91 #d1eb91 #d1eb91 "
      "#d1eb91 #d1eb91 #740377 #740377 #740377 "
      "#740377 #740377 #740377 #740377 #740377 "
      "#39d6fc #39d6fc #39d6fc #39d6fc #39d6fc "
      "#39d6fc #39d6fc #39d6fc #708e1f #708e1f "
      "#708e1f #708e1f #708e1f #708e1f #708e1f "
      "#708e1f #acb0fd #acb0fd #acb0fd #acb0fd "
      "#acb0fd #acb0fd #acb0fd #acb0fd #fd52fa "
      "#fd52fa #fd52fa #fd52fa #fd52fa #fd52fa "
      "#fd52fa #fd52fa #01840a #01840a #01840a "
      "#01840a #01840a #01840a #01840a #01840a "
      "#0626d6 #0626d6 #0626d6 #0626d6 #0626d6 "
      "#0626d6 #0626d6 #0626d6 #5c0a08 #5c0a08 "
      "#5c0a08 #5c0a08 #5c0a08 #5c0a08 #5c0a08 "
      "#5c0a08 #e3f92f #e3f92f #e3f92f #e3f92f "
      "#e3f92f #e3f92f #e3f92f #e3f92f #49ff00 "
      "#49ff00 #49ff00 #49ff00 #49ff00 #49ff00 "
      "#49ff00 #49ff00 #3ed78e #3ed78e #3ed78e "
      "#3ed78e #3ed78e #3ed78e #3ed78e #3ed78e "
      "#872cde #872cde #872cde #872cde #872cde "
      "#872cde #872cde #872cde #df5146 #df5146 "
      "#df5146 #df5146 #df5146 #df5146 #df5146 "
      "#df5146 "
};

/* Some maps for color blindness
Thanks to Vince Hradil who created them
based on http://bsp.pdx.edu/Publications/2006/SPM_McNames.pdf
*/
static char CB_CS_35[] = {
      "cb_spiral35  "
      "#c776ee #c776ee #c776ee #be75f1 "
      "#be75f1 #b574f5 #b574f5 #ac75f8 "
      "#ac75f8 #a276fb #a276fb #9878fd "
      "#9878fd #9878fd #8d7bfe #8d7bfe "
      "#837eff #837eff #7983ff #7983ff "
      "#6f88fe #6f88fe #658efc #658efc "
      "#658efc #5b94f9 #5b94f9 #529bf5 "
      "#529bf5 #4aa2f0 #4aa2f0 #42aaea "
      "#42aaea #3bb2e3 #3bb2e3 #3bb2e3 "
      "#34badb #34badb #2fc2d3 #2fc2d3 "
      "#2bcac9 #2bcac9 #27d2be #27d2be "
      "#25dab3 #25dab3 #24e1a7 #24e1a7 "
      "#24e1a7 #24e79a #24e79a #26ed8d "
      "#26ed8d #28f27f #28f27f #2cf672 "
      "#2cf672 #31f964 #31f964 #31f964 "
      "#37fa56 #37fa56 #3ffa49 #3ffa49 "
      "#47f83d #47f83d #50f431 #50f431 "
      "#5aef27 #5aef27 #5aef27 #64e81e "
      "#64e81e #6de016 #6de016 #77d70f "
      "#77d70f #80cd0a #80cd0a #89c306 "
      "#89c306 #89c306 #91b803 #91b803 "
      "#98ac01 #98ac01 #9fa000 #9fa000 "
      "#a49401 #a49401 #a98802 #a98802 "
      "#ad7c04 #ad7c04 #ad7c04 #b07007 "
      "#b07007 #b2640b #b2640b #b35810 "
      "#b35810 #b24d15 #b24d15 #b1431a "
      "#b1431a #b1431a #af3920 #af3920 "
      "#ac3026 #ac3026 #a8282c #a8282c "
      "#a42033 #a42033 #9e1939 #9e1939 "
      "#9e1939 #98133f #98133f #910e45 "
      "#910e45 #8a0a4a #8a0a4a #830650 "
      "#830650 #7b0354 #7b0354 #7b0354 "
};

static char CB_CS[] = {
      "cb_spiral "
      "#ffffff #fdfffc #fafff9 #f8fff5 "
      "#f6fff1 #f5feed #f4fde9 #f4fce4 "
      "#f4fbe0 #f4f9db #f4f6d7 #f5f4d3 "
      "#f6f0cf #f7edcc #f9e8c9 #fae4c6 "
      "#fbdfc4 #fdd9c2 #fed4c0 #ffcec0 "
      "#ffc7bf #ffc1bf #ffbac0 #ffb3c2 "
      "#fdacc4 #fca6c6 #f99fc9 #f799cc "
      "#f393d0 #ef8dd4 #ea88d8 #e483dc "
      "#de7fe0 #d77be5 #cf78e9 #c776ee "
      "#be75f1 #b574f5 #ac75f8 #a276fb "
      "#9878fd #8d7bfe #837eff #7983ff "
      "#6f88fe #658efc #5b94f9 #529bf5 "
      "#4aa2f0 #42aaea #3bb2e3 #34badb "
      "#2fc2d3 #2bcac9 #27d2be #25dab3 "
      "#24e1a7 #24e79a #26ed8d #28f27f "
      "#2cf672 #31f964 #37fa56 #3ffa49 "
      "#47f83d #50f431 #5aef27 #64e81e "
      "#6de016 #77d70f #80cd0a #89c306 "
      "#91b803 #98ac01 #9fa000 #a49401 "
      "#a98802 #ad7c04 #b07007 #b2640b "
      "#b35810 #b24d15 #b1431a #af3920 "
      "#ac3026 #a8282c #a42033 #9e1939 "
      "#98133f #910e45 #8a0a4a #830650 "
      "#7b0354 #720158 #6a005c #62005f "
      "#590061 #510163 #480264 #400464 "
      "#390663 #320862 #2b0a61 #240d5e "
      "#1e105b #191358 #141554 #101850 "
      "#0c1a4b #091c46 #061e41 #041f3c "
      "#022036 #012131 #00212c #002127 "
      "#002022 #001f1d #001d18 #001b14 "
      "#001810 #01160c #011209 #010f07 "
      "#010b04 #010702 #000401 #010101 "
};  /* changed last index to non-zero - not transparent */

// [PT: Aug 16, 2017] New(ish) colorbar.  Took "Reds_and_Blues",
// inverted each of the halves individually, and made this.
static char R_AND_B_INV_256_CMD[] = {
"Reds_and_Blues_Inv "
"#ff0b00 "
"#ff0e00 "
"#ff1100 "
"#ff1400 "
"#ff1700 "
"#ff1a00 "
"#ff1d00 "
"#ff2000 "
"#ff2200 "
"#ff2500 "
"#ff2700 "
"#ff2a00 "
"#ff2c00 "
"#ff2f00 "
"#ff3100 "
"#ff3400 "
"#ff3600 "
"#ff3800 "
"#ff3a00 "
"#ff3d00 "
"#ff3f00 "
"#ff4100 "
"#ff4300 "
"#ff4600 "
"#ff4800 "
"#ff4a00 "
"#ff4c00 "
"#ff4e00 "
"#ff5000 "
"#ff5200 "
"#ff5400 "
"#ff5700 "
"#ff5900 "
"#ff5b00 "
"#ff5d00 "
"#ff5f00 "
"#ff6100 "
"#ff6300 "
"#ff6500 "
"#ff6700 "
"#ff6900 "
"#ff6b00 "
"#ff6d00 "
"#ff6e00 "
"#ff7000 "
"#ff7200 "
"#ff7400 "
"#ff7600 "
"#ff7800 "
"#ff7a00 "
"#ff7c00 "
"#ff7e00 "
"#ff8000 "
"#ff8200 "
"#ff8300 "
"#ff8500 "
"#ff8700 "
"#ff8900 "
"#ff8b00 "
"#ff8d00 "
"#ff8e00 "
"#ff9000 "
"#ff9200 "
"#ff9400 "
"#ff9600 "
"#ff9700 "
"#ff9900 "
"#ff9b00 "
"#ff9d00 "
"#ff9f00 "
"#ffa000 "
"#ffa200 "
"#ffa400 "
"#ffa600 "
"#ffa700 "
"#ffa900 "
"#ffab00 "
"#ffad00 "
"#ffae00 "
"#ffb000 "
"#ffb200 "
"#ffb400 "
"#ffb500 "
"#ffb700 "
"#ffb900 "
"#ffba00 "
"#ffbc00 "
"#ffbe00 "
"#ffbf00 "
"#ffc100 "
"#ffc300 "
"#ffc500 "
"#ffc600 "
"#ffc800 "
"#ffca00 "
"#ffcb00 "
"#ffcd00 "
"#ffcf00 "
"#ffd000 "
"#ffd200 "
"#ffd400 "
"#ffd500 "
"#ffd700 "
"#ffd800 "
"#ffda00 "
"#ffdc00 "
"#ffdd00 "
"#ffdf00 "
"#ffe100 "
"#ffe200 "
"#ffe400 "
"#ffe500 "
"#ffe700 "
"#ffe900 "
"#ffea00 "
"#ffec00 "
"#ffee00 "
"#ffef00 "
"#fff100 "
"#fff200 "
"#fff400 "
"#fff600 "
"#fff700 "
"#fff900 "
"#fffa00 "
"#fffc00 "
"#fffd00 "
"#ffff00 "
"#00f2ff "
"#00f1ff "
"#00efff "
"#00edff "
"#00ecff "
"#00eaff "
"#00e9ff "
"#00e7ff "
"#00e5ff "
"#00e4ff "
"#00e2ff "
"#00e0ff "
"#00dfff "
"#00ddff "
"#00dbff "
"#00daff "
"#00d8ff "
"#00d6ff "
"#00d5ff "
"#00d3ff "
"#00d1ff "
"#00d0ff "
"#00ceff "
"#00ccff "
"#00cbff "
"#00c9ff "
"#00c7ff "
"#00c6ff "
"#00c4ff "
"#00c2ff "
"#00c1ff "
"#00bfff "
"#00bdff "
"#00bcff "
"#00baff "
"#00b8ff "
"#00b6ff "
"#00b5ff "
"#00b3ff "
"#00b1ff "
"#00afff "
"#00aeff "
"#00acff "
"#00aaff "
"#00a8ff "
"#00a7ff "
"#00a5ff "
"#00a3ff "
"#00a1ff "
"#00a0ff "
"#009eff "
"#009cff "
"#009aff "
"#0098ff "
"#0097ff "
"#0095ff "
"#0093ff "
"#0091ff "
"#008fff "
"#008dff "
"#008cff "
"#008aff "
"#0088ff "
"#0086ff "
"#0084ff "
"#0082ff "
"#0080ff "
"#007fff "
"#007dff "
"#007bff "
"#0079ff "
"#0077ff "
"#0075ff "
"#0073ff "
"#0071ff "
"#006fff "
"#006dff "
"#006bff "
"#0069ff "
"#0067ff "
"#0065ff "
"#0063ff "
"#0061ff "
"#005fff "
"#005dff "
"#005bff "
"#0059ff "
"#0057ff "
"#0055ff "
"#0053ff "
"#0051ff "
"#004fff "
"#004cff "
"#004aff "
"#0048ff "
"#0046ff "
"#0044ff "
"#0042ff "
"#003fff "
"#003dff "
"#003bff "
"#0038ff "
"#0036ff "
"#0034ff "
"#0031ff "
"#002fff "
"#002dff "
"#002aff "
"#0028ff "
"#0025ff "
"#0022ff "
"#0020ff "
"#001dff "
"#001aff "
"#0017ff "
"#0015ff "
"#0012ff "
"#000eff "
"#0b00ff "
"#0e00ff "
"#1200ff "
"#1500ff "
"#1700ff "
"#1a00ff "
"#1d00ff "
"#2000ff "
"#2200ff "
"#2500ff "
};

/* regular gray from white to black */
static char GRAY_CS[] = {
   "gray_scale "
   "#ffffff #010101 "
};

/* mirrored gray for +/- values */
static char GRAY_CIRCLE_CS[] = {
   "gray_circle "
   "#ffffff #010101 #ffffff "
};
/* mirrored and inverted gray for +/- values */
static char GRAY_INV_CIRCLE_CS[] = {
   "inverted_gray_circle "
   "#010101 #ffffff #010101 "
};

/* amber monochrome from bright orange to black */
static char AMBER_CS[] = {
   "amber_monochrome "
   "#ffbf00 #010100 "
};

/* mirrored amber for +/- values */
static char AMBER_CIRCLE_CS[] = {
   "amber_circle "
   "#ffbf00 #010100 #ffbf00 "
};

/* mirrored and inverted amber for +/- values */
static char AMBER_INV_CIRCLE_CS[] = {
   "inverted_amber_circle "
   "#010100 #ffbf00 #010100 "
};

/* mirrored and inverted amber for +/- values */
static char AMBER_REDTOP_BLUEBOT_CS[] = {
   "amber_redtop_bluebot "
" #ff0000 "
" #febe00 #fdbd00 #fcbd00 #fbbc00 "
" #fabb00 #f9ba00 #f8ba00 #f7b900 "
" #f6b800 #f5b700 #f4b700 #f3b600 "
" #f2b500 #f1b400 #f0b400 #efb300 "
" #eeb200 #edb100 #ecb100 #ebb000 "
" #eaaf00 #e9ae00 #e8ae00 #e7ad00 "
" #e6ac00 #e5ab00 #e4ab00 #e3aa00 "
" #e2a900 #e1a900 #e0a800 #dfa700 "
" #dea600 #dda600 #dca500 #dba400 "
" #daa300 #d9a300 #d8a200 #d7a100 "
" #d6a000 #d5a000 #d49f00 #d39e00 "
" #d29d00 #d19d00 #d09c00 #cf9b00 "
" #ce9a00 #cd9a00 #cc9900 #cb9800 "
" #ca9700 #c99700 #c89600 #c79500 "
" #c69400 #c59400 #c49300 #c39200 "
" #c29200 #c19100 #c09000 #bf8f00 "
" #bf8f00 #be8e00 #bd8d00 #bc8c00 "
" #bb8c00 #ba8b00 #b98a00 #b88900 "
" #b78900 #b68800 #b58700 #b48600 "
" #b38600 #b28500 #b18400 #b08300 "
" #af8300 #ae8200 #ad8100 #ac8000 "
" #ab8000 #aa7f00 #a97e00 #a87e00 "
" #a77d00 #a67c00 #a57b00 #a47b00 "
" #a37a00 #a27900 #a17800 #a07800 "
" #9f7700 #9e7600 #9d7500 #9c7500 "
" #9b7400 #9a7300 #997200 #987200 "
" #977100 #967000 #956f00 #946f00 "
" #936e00 #926d00 #916c00 #906c00 "
" #8f6b00 #8e6a00 #8d6a00 #8c6900 "
" #8b6800 #8a6700 #896700 #886600 "
" #876500 #866400 #856400 #846300 "
" #836200 #826100 #816100 #806000 "
" #7f5f00 #7e5e00 #7d5e00 #7c5d00 "
" #7b5c00 #7a5b00 #795b00 #785a00 "
" #775900 #765800 #755800 #745700 "
" #735600 #725500 #715500 #705400 "
" #6f5300 #6e5300 #6d5200 #6c5100 #6b5000 "
" #6a5000 #694f00 #684e00 #674d00 #664d00 "
" #654c00 #644b00 #634a00 #624a00 #614900 "
" #604800 #5f4700 #5e4700 #5d4600 #5c4500 "
" #5b4400 #5a4400 #594300 #584200 #574100 "
" #564100 #554000 #543f00 #533f00 #523e00 "
" #513d00 #503c00 #4f3c00 #4e3b00 #4d3a00 "
" #4c3900 #4b3900 #4a3800 #493700 #483600 "
" #473600 #463500 #453400 #443300 #433300 "
" #423200 #413100 #403000 #403000 #3f2f00 "
" #3e2e00 #3d2d00 #3c2d00 #3b2c00 #3a2b00 "
" #392b00 #382a00 #372900 #362800 #352800 "
" #342700 #332600 #322500 #312500 #302400 "
" #2f2300 #2e2200 #2d2200 #2c2100 #2b2000 "
" #2a1f00 #291f00 #281e00 #271d00 #261c00 "
" #251c00 #241b00 #231a00 #221900 #211900 "
" #201800 #1f1700 #1e1600 #1d1600 #1c1500 "
" #1b1400 #1a1400 #191300 #181200 #171100 "
" #161100 #151000 #140f00 #130e00 #120e00 "
" #110d00 #100c00 #0f0b00 #0e0b00 #0d0a00 "
" #0c0900 #0b0800 #0a0800 #090700 #080600 "
" #070500 #060500 #050400 #040300 "
" #0000ff "
};

/* green monochrome from bright green to black */
static char GREEN_CS[] = {
   "green_monochrome "
   "#00ff00 #000100 "
};

/* blue monochrome from bright blue to black  - really "azure" */
static char BLUE_CS[] = {
   "blue_monochrome "
   "#007fff #000001 "
};

/* red monochrome from bright red to black */
static char RED_CS[] = {
   "red_monochrome "
   "#ff0000 #010000 "
};

/* amber variant for @AddEdge */
static char ADD_EDGE[] = {                /* generated with: MakeColorMap -fn  */
   "Add_Edge "                            /*    Fiducials_Ncol -ahc Add_Edge   */
   "#00FFFF #66FF00 #00FF00 #660000 "     /*    -flipud  */
   "#FF0000 #FFBF00 #FEBE00 #FDBD00 "     /* with Fiducials_Ncol containing */
   "#FBBD00 #FABC00 #F9BB00 #F8BA00 "     /* 0.4860    0.8913    0.7621   0 */
   "#F7B900 #F5B800 #F4B700 #F3B600 "     /* 0.7   0     0.7   1 */
   "#F2B500 #F0B400 #EFB400 #EEB300 "     /* 0.4514    0.0439    0.0272 2 */
   "#EDB200 #ECB100 #EAB000 #E9AF00 "     /* 0.0093    0.9400    0.5966   3 */
   "#E8AE00 #E7AD00 #E6AC00 #E4AB00 "     /* 0.9810    0.0697    0.0450 4  */
   "#E3AB00 #E2AA00 #E1A900 #DFA800 "     /* 0.13     0.10  0.0   5  */
   "#DEA700 #DDA600 #DCA500 #DBA400 "     /* 0.42     0.32  0     128 */
   "#D9A300 #D8A200 #D7A200 #D6A100 "     /* 1     0.75  0     250 */
   "#D5A000 #D39F00 #D29E00 #D19D00 "     /* 1     0     0     251 */
   "#D09C00 #CF9B00 #CD9A00 #CC9A00 "     /* 0.0   0.0   0.4     252 */
   "#CB9900 #CA9800 #C89700 #C79600 "     /* 0     1     0     253 */
   "#C69500 #C59400 #C49300 #C29200 "     /* 0.4   1     0     254 */
   "#C19100 #C09100 #BF9000 #BE8F00 "     /* 0     1     1     255  */
   "#BC8E00 #BB8D00 #BA8C00 #B98B00 "
   "#B78A00 #B68900 #B58800 #B48800 "
   "#B38700 #B18600 #B08500 #AF8400 "
   "#AE8300 #AD8200 #AB8100 #AA8000 "
   "#A97F00 #A87F00 #A77E00 #A57D00 "
   "#A47C00 #A37B00 #A27A00 #A07900 "
   "#9F7800 #9E7700 #9D7600 #9C7600 "
   "#9A7500 #997400 #987300 #977200 "
   "#967100 #947000 #936F00 #926E00 "
   "#916D00 #8F6D00 #8E6C00 #8D6B00 "
   "#8C6A00 #8B6900 #896800 #886700 "
   "#876600 #866500 #856400 #836400 "
   "#826300 #816200 #806100 #7E6000 "
   "#7D5F00 #7C5E00 #7B5D00 #7A5C00 "
   "#785B00 #775B00 #765A00 #755900 "
   "#745800 #725700 #715600 #705500 "
   "#6F5400 #6E5300 #6C5200 #6B5200 "
   "#6A5100 #6A5100 #695000 #695000 "
   "#684F00 #674F00 #674E00 #664E00 "
   "#664D00 #654D00 #644D00 #644C00 "
   "#634C00 #634B00 #624B00 #614A00 "
   "#614A00 #604900 #604900 #5F4800 "
   "#5E4800 #5E4800 #5D4700 #5D4700 "
   "#5C4600 #5B4600 #5B4500 #5A4500 "
   "#5A4400 #594400 #584300 #584300 "
   "#574300 #574200 #564200 #554100 "
   "#554100 #544000 #544000 #533F00 "
   "#523F00 #523E00 #513E00 #513E00 "
   "#503D00 #4F3D00 #4F3C00 #4E3C00 "
   "#4E3B00 #4D3B00 #4C3A00 #4C3A00 "
   "#4B3900 #4B3900 #4A3900 #493800 "
   "#493800 #483700 #483700 #473600 "
   "#463600 #463500 #453500 #453400 "
   "#443400 #433300 #433300 #423300 "
   "#423200 #413200 #403100 #403100 "
   "#3F3000 #3F3000 #3E2F00 #3D2F00 "
   "#3D2E00 #3C2E00 #3C2E00 #3B2D00 "
   "#3A2D00 #3A2C00 #392C00 #392B00 "
   "#382B00 #372A00 #372A00 #362900 "
   "#362900 #352900 #342800 #342800 "
   "#332700 #332700 #322600 #312600 "
   "#312500 #302500 #302400 #2F2400 "
   "#2E2400 #2E2300 #2D2300 #2D2200 "
   "#2C2200 #2B2100 #2B2100 #2A2000 "
   "#2A2000 #291F00 #281F00 #281F00 "
   "#271E00 #271E00 #261D00 #251D00 "
   "#251C00 #241C00 #241B00 #231B00 "
   "#221A00 #221A00 #211A00 #FA120B "
   "#02F098 #730B07 #B200B2 #7CE3C2 "
};

/* FreeSurfer colormap from 0 to 255
Created from FreeSurferColorLUT.txt
this way:
MakeColorMap   -fscolut 0 255 \
               -ahc FreeSurfer_255 \
               -flipud > fs_pal.pal
Open fs_pal.pal, remove the zeroth color
   (all 0 #000000 ) from the bottom
Add _CMD (indicating direct color
mapping needed )to var name and add
  entry in pbar.c
*/
static char FREESURFER_SEG_255_CMD[]={
   "FreeSurfer_Seg_i255 "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #C596FA #C53AFA #CD3F4E "
   "#00E200 #68FFFF #808080 #FFCC66 "
   "#8020FF #800000 #791188 #CC99CC "
   "#80FF80 #20C8FF #C4A080 #008000 "
   "#8080FF #FF0000 #0000FF #400040 "
   "#FFFF00 #FF8080 #FFCC99 #003280 "
   "#806040 #007E4B #80C4A4 #0064FF "
   "#C4C400 #FFA4A4 #00C4FF #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #EE3B3B #8B795E #EEEED1 "
   "#CDCD00 #FF0000 #E0E0E0 #8B795E "
   "#4682B5 #4682B4 #EFA0DF #34D1E2 "
   "#FFFFFE #DDE244 #8B8B8B #8604A0 "
   "#418714 #418714 #152784 #152784 "
   "#483D8B #FF0000 #EEAEEE #DD27C8 "
   "#EE3B3B #9313AD #1E90FF #228B22 "
   "#1AED39 #85CBE5 #ADFF2F #00008B "
   "#EE0000 #4AFF4A #C8C8C8 #EEEED1 "
   "#CDB38B #FF1493 #7C8CB3 #7C90B2 "
   "#7C8FB2 #7C8EB2 #7C8DB2 #7F8CB2 "
   "#7E8CB2 #7D8CB2 #7C8CB2 #7C8CB3 "
   "#7C90B2 #7C8FB2 #7C8EB2 #7C8DB2 "
   "#7F8CB2 #7E8CB2 #7D8CB2 #7C8CB2 "
   "#8B8B8B #A020F0 #CD0A7D #CD0A7D "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #8B8B8B #8B8B8B #8B8B8B "
   "#8B8B8B #FAFF32 #EAA91E #FFDAB9 "
   "#FFDAB9 #A46CE2 #A46CE2 #A46CE2 "
   "#FF940A #FF940A #C846FF #781286 "
   "#781286 #7A8732 #7A8732 #78BE96 "
   "#7A8732 #4A9B3C #783E2B #4A9B3C "
   "#333287 #7A8732 #87324A #643264 "
   "#00C8DD #A020F0 #87CEEB #A52A2A "
   "#00FF7F #FFA500 #FFA500 #3C3AD2 "
   "#50C462 #67FFFF #DCD814 #0D30FF "
   "#EC0DB0 #7ABADC #00760E #00760E "
   "#E69422 #DCF8A4 #009400 #C43AFA "
   "#781286 #CD3E4E #00E100 #CD3E4E "
   "#7A8732 #4A9B3C #783E2B #4A9B3C "
   "#333287 #7A8732 #87324A #643264 "
   "#00C8C8 #A020F0 #87CEEB #A52A2A "
   "#00FF7F #FFA500 #FFA500 #3C3C3C "
   "#3C3AD2 #3C3AD2 #3C3AD2 #3C3AD2 "
   "#50C462 #67FFFF #DCD814 #779FB0 "
   "#2ACCA4 #CCB68E #0C30FF #EC0DB0 "
   "#7ABADC #00760E #00760E #E69422 "
   "#DCF8A4 #009400 #C43AFA #781286 "
   "#CD3E4E #F5F5F5 #CD3E4E "
};

static char RedBlueGreen_CMD[] = {
      "RedBlueGreen "
      "#ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 "
      "#ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 "
      "#ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 "
      "#ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 "
      "#ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 "
      "#ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 "
      "#ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 "
      "#ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 #ff1010 "
      "#ff1010 #ff1010 #ff1010 #ff1010 #ff1010 "
      "#1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff "
      "#1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff "
      "#1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff "
      "#1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff "
      "#1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff "
      "#1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff "
      "#1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff "
      "#1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff #1010ff "
      "#1010ff #1010ff #1010ff #1010ff #1010ff "
      "#10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 "
      "#10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 "
      "#10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 "
      "#10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 "
      "#10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 "
      "#10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 "
      "#10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 "
      "#10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10 "
      "#10ff10 #10ff10 #10ff10 #10ff10 #10ff10 #10ff10"
};

/***--------------------------------------------------------------***/
/*** These are from the Viridis colormaps -- 17 Nov 2016 -- RWCox ***/

/*** The colors are defined as RGB triples of floats, unlike the  ***/
/*** ones above, where the colors are defined as byte #triples.   ***/
/*** See pbar.c for how these arrays are loading into AFNI's GUI. ***/

#define      magma_num 256
static char *magma_name = "Magma" ;
static float magma_data[3*magma_num] =
    {0.001462, 0.000466, 0.013866,
     0.002258, 0.001295, 0.018331,
     0.003279, 0.002305, 0.023708,
     0.004512, 0.003490, 0.029965,
     0.005950, 0.004843, 0.037130,
     0.007588, 0.006356, 0.044973,
     0.009426, 0.008022, 0.052844,
     0.011465, 0.009828, 0.060750,
     0.013708, 0.011771, 0.068667,
     0.016156, 0.013840, 0.076603,
     0.018815, 0.016026, 0.084584,
     0.021692, 0.018320, 0.092610,
     0.024792, 0.020715, 0.100676,
     0.028123, 0.023201, 0.108787,
     0.031696, 0.025765, 0.116965,
     0.035520, 0.028397, 0.125209,
     0.039608, 0.031090, 0.133515,
     0.043830, 0.033830, 0.141886,
     0.048062, 0.036607, 0.150327,
     0.052320, 0.039407, 0.158841,
     0.056615, 0.042160, 0.167446,
     0.060949, 0.044794, 0.176129,
     0.065330, 0.047318, 0.184892,
     0.069764, 0.049726, 0.193735,
     0.074257, 0.052017, 0.202660,
     0.078815, 0.054184, 0.211667,
     0.083446, 0.056225, 0.220755,
     0.088155, 0.058133, 0.229922,
     0.092949, 0.059904, 0.239164,
     0.097833, 0.061531, 0.248477,
     0.102815, 0.063010, 0.257854,
     0.107899, 0.064335, 0.267289,
     0.113094, 0.065492, 0.276784,
     0.118405, 0.066479, 0.286321,
     0.123833, 0.067295, 0.295879,
     0.129380, 0.067935, 0.305443,
     0.135053, 0.068391, 0.315000,
     0.140858, 0.068654, 0.324538,
     0.146785, 0.068738, 0.334011,
     0.152839, 0.068637, 0.343404,
     0.159018, 0.068354, 0.352688,
     0.165308, 0.067911, 0.361816,
     0.171713, 0.067305, 0.370771,
     0.178212, 0.066576, 0.379497,
     0.184801, 0.065732, 0.387973,
     0.191460, 0.064818, 0.396152,
     0.198177, 0.063862, 0.404009,
     0.204935, 0.062907, 0.411514,
     0.211718, 0.061992, 0.418647,
     0.218512, 0.061158, 0.425392,
     0.225302, 0.060445, 0.431742,
     0.232077, 0.059889, 0.437695,
     0.238826, 0.059517, 0.443256,
     0.245543, 0.059352, 0.448436,
     0.252220, 0.059415, 0.453248,
     0.258857, 0.059706, 0.457710,
     0.265447, 0.060237, 0.461840,
     0.271994, 0.060994, 0.465660,
     0.278493, 0.061978, 0.469190,
     0.284951, 0.063168, 0.472451,
     0.291366, 0.064553, 0.475462,
     0.297740, 0.066117, 0.478243,
     0.304081, 0.067835, 0.480812,
     0.310382, 0.069702, 0.483186,
     0.316654, 0.071690, 0.485380,
     0.322899, 0.073782, 0.487408,
     0.329114, 0.075972, 0.489287,
     0.335308, 0.078236, 0.491024,
     0.341482, 0.080564, 0.492631,
     0.347636, 0.082946, 0.494121,
     0.353773, 0.085373, 0.495501,
     0.359898, 0.087831, 0.496778,
     0.366012, 0.090314, 0.497960,
     0.372116, 0.092816, 0.499053,
     0.378211, 0.095332, 0.500067,
     0.384299, 0.097855, 0.501002,
     0.390384, 0.100379, 0.501864,
     0.396467, 0.102902, 0.502658,
     0.402548, 0.105420, 0.503386,
     0.408629, 0.107930, 0.504052,
     0.414709, 0.110431, 0.504662,
     0.420791, 0.112920, 0.505215,
     0.426877, 0.115395, 0.505714,
     0.432967, 0.117855, 0.506160,
     0.439062, 0.120298, 0.506555,
     0.445163, 0.122724, 0.506901,
     0.451271, 0.125132, 0.507198,
     0.457386, 0.127522, 0.507448,
     0.463508, 0.129893, 0.507652,
     0.469640, 0.132245, 0.507809,
     0.475780, 0.134577, 0.507921,
     0.481929, 0.136891, 0.507989,
     0.488088, 0.139186, 0.508011,
     0.494258, 0.141462, 0.507988,
     0.500438, 0.143719, 0.507920,
     0.506629, 0.145958, 0.507806,
     0.512831, 0.148179, 0.507648,
     0.519045, 0.150383, 0.507443,
     0.525270, 0.152569, 0.507192,
     0.531507, 0.154739, 0.506895,
     0.537755, 0.156894, 0.506551,
     0.544015, 0.159033, 0.506159,
     0.550287, 0.161158, 0.505719,
     0.556571, 0.163269, 0.505230,
     0.562866, 0.165368, 0.504692,
     0.569172, 0.167454, 0.504105,
     0.575490, 0.169530, 0.503466,
     0.581819, 0.171596, 0.502777,
     0.588158, 0.173652, 0.502035,
     0.594508, 0.175701, 0.501241,
     0.600868, 0.177743, 0.500394,
     0.607238, 0.179779, 0.499492,
     0.613617, 0.181811, 0.498536,
     0.620005, 0.183840, 0.497524,
     0.626401, 0.185867, 0.496456,
     0.632805, 0.187893, 0.495332,
     0.639216, 0.189921, 0.494150,
     0.645633, 0.191952, 0.492910,
     0.652056, 0.193986, 0.491611,
     0.658483, 0.196027, 0.490253,
     0.664915, 0.198075, 0.488836,
     0.671349, 0.200133, 0.487358,
     0.677786, 0.202203, 0.485819,
     0.684224, 0.204286, 0.484219,
     0.690661, 0.206384, 0.482558,
     0.697098, 0.208501, 0.480835,
     0.703532, 0.210638, 0.479049,
     0.709962, 0.212797, 0.477201,
     0.716387, 0.214982, 0.475290,
     0.722805, 0.217194, 0.473316,
     0.729216, 0.219437, 0.471279,
     0.735616, 0.221713, 0.469180,
     0.742004, 0.224025, 0.467018,
     0.748378, 0.226377, 0.464794,
     0.754737, 0.228772, 0.462509,
     0.761077, 0.231214, 0.460162,
     0.767398, 0.233705, 0.457755,
     0.773695, 0.236249, 0.455289,
     0.779968, 0.238851, 0.452765,
     0.786212, 0.241514, 0.450184,
     0.792427, 0.244242, 0.447543,
     0.798608, 0.247040, 0.444848,
     0.804752, 0.249911, 0.442102,
     0.810855, 0.252861, 0.439305,
     0.816914, 0.255895, 0.436461,
     0.822926, 0.259016, 0.433573,
     0.828886, 0.262229, 0.430644,
     0.834791, 0.265540, 0.427671,
     0.840636, 0.268953, 0.424666,
     0.846416, 0.272473, 0.421631,
     0.852126, 0.276106, 0.418573,
     0.857763, 0.279857, 0.415496,
     0.863320, 0.283729, 0.412403,
     0.868793, 0.287728, 0.409303,
     0.874176, 0.291859, 0.406205,
     0.879464, 0.296125, 0.403118,
     0.884651, 0.300530, 0.400047,
     0.889731, 0.305079, 0.397002,
     0.894700, 0.309773, 0.393995,
     0.899552, 0.314616, 0.391037,
     0.904281, 0.319610, 0.388137,
     0.908884, 0.324755, 0.385308,
     0.913354, 0.330052, 0.382563,
     0.917689, 0.335500, 0.379915,
     0.921884, 0.341098, 0.377376,
     0.925937, 0.346844, 0.374959,
     0.929845, 0.352734, 0.372677,
     0.933606, 0.358764, 0.370541,
     0.937221, 0.364929, 0.368567,
     0.940687, 0.371224, 0.366762,
     0.944006, 0.377643, 0.365136,
     0.947180, 0.384178, 0.363701,
     0.950210, 0.390820, 0.362468,
     0.953099, 0.397563, 0.361438,
     0.955849, 0.404400, 0.360619,
     0.958464, 0.411324, 0.360014,
     0.960949, 0.418323, 0.359630,
     0.963310, 0.425390, 0.359469,
     0.965549, 0.432519, 0.359529,
     0.967671, 0.439703, 0.359810,
     0.969680, 0.446936, 0.360311,
     0.971582, 0.454210, 0.361030,
     0.973381, 0.461520, 0.361965,
     0.975082, 0.468861, 0.363111,
     0.976690, 0.476226, 0.364466,
     0.978210, 0.483612, 0.366025,
     0.979645, 0.491014, 0.367783,
     0.981000, 0.498428, 0.369734,
     0.982279, 0.505851, 0.371874,
     0.983485, 0.513280, 0.374198,
     0.984622, 0.520713, 0.376698,
     0.985693, 0.528148, 0.379371,
     0.986700, 0.535582, 0.382210,
     0.987646, 0.543015, 0.385210,
     0.988533, 0.550446, 0.388365,
     0.989363, 0.557873, 0.391671,
     0.990138, 0.565296, 0.395122,
     0.990871, 0.572706, 0.398714,
     0.991558, 0.580107, 0.402441,
     0.992196, 0.587502, 0.406299,
     0.992785, 0.594891, 0.410283,
     0.993326, 0.602275, 0.414390,
     0.993834, 0.609644, 0.418613,
     0.994309, 0.616999, 0.422950,
     0.994738, 0.624350, 0.427397,
     0.995122, 0.631696, 0.431951,
     0.995480, 0.639027, 0.436607,
     0.995810, 0.646344, 0.441361,
     0.996096, 0.653659, 0.446213,
     0.996341, 0.660969, 0.451160,
     0.996580, 0.668256, 0.456192,
     0.996775, 0.675541, 0.461314,
     0.996925, 0.682828, 0.466526,
     0.997077, 0.690088, 0.471811,
     0.997186, 0.697349, 0.477182,
     0.997254, 0.704611, 0.482635,
     0.997325, 0.711848, 0.488154,
     0.997351, 0.719089, 0.493755,
     0.997351, 0.726324, 0.499428,
     0.997341, 0.733545, 0.505167,
     0.997285, 0.740772, 0.510983,
     0.997228, 0.747981, 0.516859,
     0.997138, 0.755190, 0.522806,
     0.997019, 0.762398, 0.528821,
     0.996898, 0.769591, 0.534892,
     0.996727, 0.776795, 0.541039,
     0.996571, 0.783977, 0.547233,
     0.996369, 0.791167, 0.553499,
     0.996162, 0.798348, 0.559820,
     0.995932, 0.805527, 0.566202,
     0.995680, 0.812706, 0.572645,
     0.995424, 0.819875, 0.579140,
     0.995131, 0.827052, 0.585701,
     0.994851, 0.834213, 0.592307,
     0.994524, 0.841387, 0.598983,
     0.994222, 0.848540, 0.605696,
     0.993866, 0.855711, 0.612482,
     0.993545, 0.862859, 0.619299,
     0.993170, 0.870024, 0.626189,
     0.992831, 0.877168, 0.633109,
     0.992440, 0.884330, 0.640099,
     0.992089, 0.891470, 0.647116,
     0.991688, 0.898627, 0.654202,
     0.991332, 0.905763, 0.661309,
     0.990930, 0.912915, 0.668481,
     0.990570, 0.920049, 0.675675,
     0.990175, 0.927196, 0.682926,
     0.989815, 0.934329, 0.690198,
     0.989434, 0.941470, 0.697519,
     0.989077, 0.948604, 0.704863,
     0.988717, 0.955742, 0.712242,
     0.988367, 0.962878, 0.719649,
     0.988033, 0.970012, 0.727077,
     0.987691, 0.977154, 0.734536,
     0.987387, 0.984288, 0.742002,
     0.987053, 0.991438, 0.749504 } ;

#if 0
#define      inferno_num 256
static char *inferno_name = "Inferno" ;
static float inferno_data[3*inferno_num] =
                {0.001462, 0.000466, 0.013866,
                 0.002267, 0.001270, 0.018570,
                 0.003299, 0.002249, 0.024239,
                 0.004547, 0.003392, 0.030909,
                 0.006006, 0.004692, 0.038558,
                 0.007676, 0.006136, 0.046836,
                 0.009561, 0.007713, 0.055143,
                 0.011663, 0.009417, 0.063460,
                 0.013995, 0.011225, 0.071862,
                 0.016561, 0.013136, 0.080282,
                 0.019373, 0.015133, 0.088767,
                 0.022447, 0.017199, 0.097327,
                 0.025793, 0.019331, 0.105930,
                 0.029432, 0.021503, 0.114621,
                 0.033385, 0.023702, 0.123397,
                 0.037668, 0.025921, 0.132232,
                 0.042253, 0.028139, 0.141141,
                 0.046915, 0.030324, 0.150164,
                 0.051644, 0.032474, 0.159254,
                 0.056449, 0.034569, 0.168414,
                 0.061340, 0.036590, 0.177642,
                 0.066331, 0.038504, 0.186962,
                 0.071429, 0.040294, 0.196354,
                 0.076637, 0.041905, 0.205799,
                 0.081962, 0.043328, 0.215289,
                 0.087411, 0.044556, 0.224813,
                 0.092990, 0.045583, 0.234358,
                 0.098702, 0.046402, 0.243904,
                 0.104551, 0.047008, 0.253430,
                 0.110536, 0.047399, 0.262912,
                 0.116656, 0.047574, 0.272321,
                 0.122908, 0.047536, 0.281624,
                 0.129285, 0.047293, 0.290788,
                 0.135778, 0.046856, 0.299776,
                 0.142378, 0.046242, 0.308553,
                 0.149073, 0.045468, 0.317085,
                 0.155850, 0.044559, 0.325338,
                 0.162689, 0.043554, 0.333277,
                 0.169575, 0.042489, 0.340874,
                 0.176493, 0.041402, 0.348111,
                 0.183429, 0.040329, 0.354971,
                 0.190367, 0.039309, 0.361447,
                 0.197297, 0.038400, 0.367535,
                 0.204209, 0.037632, 0.373238,
                 0.211095, 0.037030, 0.378563,
                 0.217949, 0.036615, 0.383522,
                 0.224763, 0.036405, 0.388129,
                 0.231538, 0.036405, 0.392400,
                 0.238273, 0.036621, 0.396353,
                 0.244967, 0.037055, 0.400007,
                 0.251620, 0.037705, 0.403378,
                 0.258234, 0.038571, 0.406485,
                 0.264810, 0.039647, 0.409345,
                 0.271347, 0.040922, 0.411976,
                 0.277850, 0.042353, 0.414392,
                 0.284321, 0.043933, 0.416608,
                 0.290763, 0.045644, 0.418637,
                 0.297178, 0.047470, 0.420491,
                 0.303568, 0.049396, 0.422182,
                 0.309935, 0.051407, 0.423721,
                 0.316282, 0.053490, 0.425116,
                 0.322610, 0.055634, 0.426377,
                 0.328921, 0.057827, 0.427511,
                 0.335217, 0.060060, 0.428524,
                 0.341500, 0.062325, 0.429425,
                 0.347771, 0.064616, 0.430217,
                 0.354032, 0.066925, 0.430906,
                 0.360284, 0.069247, 0.431497,
                 0.366529, 0.071579, 0.431994,
                 0.372768, 0.073915, 0.432400,
                 0.379001, 0.076253, 0.432719,
                 0.385228, 0.078591, 0.432955,
                 0.391453, 0.080927, 0.433109,
                 0.397674, 0.083257, 0.433183,
                 0.403894, 0.085580, 0.433179,
                 0.410113, 0.087896, 0.433098,
                 0.416331, 0.090203, 0.432943,
                 0.422549, 0.092501, 0.432714,
                 0.428768, 0.094790, 0.432412,
                 0.434987, 0.097069, 0.432039,
                 0.441207, 0.099338, 0.431594,
                 0.447428, 0.101597, 0.431080,
                 0.453651, 0.103848, 0.430498,
                 0.459875, 0.106089, 0.429846,
                 0.466100, 0.108322, 0.429125,
                 0.472328, 0.110547, 0.428334,
                 0.478558, 0.112764, 0.427475,
                 0.484789, 0.114974, 0.426548,
                 0.491022, 0.117179, 0.425552,
                 0.497257, 0.119379, 0.424488,
                 0.503493, 0.121575, 0.423356,
                 0.509730, 0.123769, 0.422156,
                 0.515967, 0.125960, 0.420887,
                 0.522206, 0.128150, 0.419549,
                 0.528444, 0.130341, 0.418142,
                 0.534683, 0.132534, 0.416667,
                 0.540920, 0.134729, 0.415123,
                 0.547157, 0.136929, 0.413511,
                 0.553392, 0.139134, 0.411829,
                 0.559624, 0.141346, 0.410078,
                 0.565854, 0.143567, 0.408258,
                 0.572081, 0.145797, 0.406369,
                 0.578304, 0.148039, 0.404411,
                 0.584521, 0.150294, 0.402385,
                 0.590734, 0.152563, 0.400290,
                 0.596940, 0.154848, 0.398125,
                 0.603139, 0.157151, 0.395891,
                 0.609330, 0.159474, 0.393589,
                 0.615513, 0.161817, 0.391219,
                 0.621685, 0.164184, 0.388781,
                 0.627847, 0.166575, 0.386276,
                 0.633998, 0.168992, 0.383704,
                 0.640135, 0.171438, 0.381065,
                 0.646260, 0.173914, 0.378359,
                 0.652369, 0.176421, 0.375586,
                 0.658463, 0.178962, 0.372748,
                 0.664540, 0.181539, 0.369846,
                 0.670599, 0.184153, 0.366879,
                 0.676638, 0.186807, 0.363849,
                 0.682656, 0.189501, 0.360757,
                 0.688653, 0.192239, 0.357603,
                 0.694627, 0.195021, 0.354388,
                 0.700576, 0.197851, 0.351113,
                 0.706500, 0.200728, 0.347777,
                 0.712396, 0.203656, 0.344383,
                 0.718264, 0.206636, 0.340931,
                 0.724103, 0.209670, 0.337424,
                 0.729909, 0.212759, 0.333861,
                 0.735683, 0.215906, 0.330245,
                 0.741423, 0.219112, 0.326576,
                 0.747127, 0.222378, 0.322856,
                 0.752794, 0.225706, 0.319085,
                 0.758422, 0.229097, 0.315266,
                 0.764010, 0.232554, 0.311399,
                 0.769556, 0.236077, 0.307485,
                 0.775059, 0.239667, 0.303526,
                 0.780517, 0.243327, 0.299523,
                 0.785929, 0.247056, 0.295477,
                 0.791293, 0.250856, 0.291390,
                 0.796607, 0.254728, 0.287264,
                 0.801871, 0.258674, 0.283099,
                 0.807082, 0.262692, 0.278898,
                 0.812239, 0.266786, 0.274661,
                 0.817341, 0.270954, 0.270390,
                 0.822386, 0.275197, 0.266085,
                 0.827372, 0.279517, 0.261750,
                 0.832299, 0.283913, 0.257383,
                 0.837165, 0.288385, 0.252988,
                 0.841969, 0.292933, 0.248564,
                 0.846709, 0.297559, 0.244113,
                 0.851384, 0.302260, 0.239636,
                 0.855992, 0.307038, 0.235133,
                 0.860533, 0.311892, 0.230606,
                 0.865006, 0.316822, 0.226055,
                 0.869409, 0.321827, 0.221482,
                 0.873741, 0.326906, 0.216886,
                 0.878001, 0.332060, 0.212268,
                 0.882188, 0.337287, 0.207628,
                 0.886302, 0.342586, 0.202968,
                 0.890341, 0.347957, 0.198286,
                 0.894305, 0.353399, 0.193584,
                 0.898192, 0.358911, 0.188860,
                 0.902003, 0.364492, 0.184116,
                 0.905735, 0.370140, 0.179350,
                 0.909390, 0.375856, 0.174563,
                 0.912966, 0.381636, 0.169755,
                 0.916462, 0.387481, 0.164924,
                 0.919879, 0.393389, 0.160070,
                 0.923215, 0.399359, 0.155193,
                 0.926470, 0.405389, 0.150292,
                 0.929644, 0.411479, 0.145367,
                 0.932737, 0.417627, 0.140417,
                 0.935747, 0.423831, 0.135440,
                 0.938675, 0.430091, 0.130438,
                 0.941521, 0.436405, 0.125409,
                 0.944285, 0.442772, 0.120354,
                 0.946965, 0.449191, 0.115272,
                 0.949562, 0.455660, 0.110164,
                 0.952075, 0.462178, 0.105031,
                 0.954506, 0.468744, 0.099874,
                 0.956852, 0.475356, 0.094695,
                 0.959114, 0.482014, 0.089499,
                 0.961293, 0.488716, 0.084289,
                 0.963387, 0.495462, 0.079073,
                 0.965397, 0.502249, 0.073859,
                 0.967322, 0.509078, 0.068659,
                 0.969163, 0.515946, 0.063488,
                 0.970919, 0.522853, 0.058367,
                 0.972590, 0.529798, 0.053324,
                 0.974176, 0.536780, 0.048392,
                 0.975677, 0.543798, 0.043618,
                 0.977092, 0.550850, 0.039050,
                 0.978422, 0.557937, 0.034931,
                 0.979666, 0.565057, 0.031409,
                 0.980824, 0.572209, 0.028508,
                 0.981895, 0.579392, 0.026250,
                 0.982881, 0.586606, 0.024661,
                 0.983779, 0.593849, 0.023770,
                 0.984591, 0.601122, 0.023606,
                 0.985315, 0.608422, 0.024202,
                 0.985952, 0.615750, 0.025592,
                 0.986502, 0.623105, 0.027814,
                 0.986964, 0.630485, 0.030908,
                 0.987337, 0.637890, 0.034916,
                 0.987622, 0.645320, 0.039886,
                 0.987819, 0.652773, 0.045581,
                 0.987926, 0.660250, 0.051750,
                 0.987945, 0.667748, 0.058329,
                 0.987874, 0.675267, 0.065257,
                 0.987714, 0.682807, 0.072489,
                 0.987464, 0.690366, 0.079990,
                 0.987124, 0.697944, 0.087731,
                 0.986694, 0.705540, 0.095694,
                 0.986175, 0.713153, 0.103863,
                 0.985566, 0.720782, 0.112229,
                 0.984865, 0.728427, 0.120785,
                 0.984075, 0.736087, 0.129527,
                 0.983196, 0.743758, 0.138453,
                 0.982228, 0.751442, 0.147565,
                 0.981173, 0.759135, 0.156863,
                 0.980032, 0.766837, 0.166353,
                 0.978806, 0.774545, 0.176037,
                 0.977497, 0.782258, 0.185923,
                 0.976108, 0.789974, 0.196018,
                 0.974638, 0.797692, 0.206332,
                 0.973088, 0.805409, 0.216877,
                 0.971468, 0.813122, 0.227658,
                 0.969783, 0.820825, 0.238686,
                 0.968041, 0.828515, 0.249972,
                 0.966243, 0.836191, 0.261534,
                 0.964394, 0.843848, 0.273391,
                 0.962517, 0.851476, 0.285546,
                 0.960626, 0.859069, 0.298010,
                 0.958720, 0.866624, 0.310820,
                 0.956834, 0.874129, 0.323974,
                 0.954997, 0.881569, 0.337475,
                 0.953215, 0.888942, 0.351369,
                 0.951546, 0.896226, 0.365627,
                 0.950018, 0.903409, 0.380271,
                 0.948683, 0.910473, 0.395289,
                 0.947594, 0.917399, 0.410665,
                 0.946809, 0.924168, 0.426373,
                 0.946392, 0.930761, 0.442367,
                 0.946403, 0.937159, 0.458592,
                 0.946903, 0.943348, 0.474970,
                 0.947937, 0.949318, 0.491426,
                 0.949545, 0.955063, 0.507860,
                 0.951740, 0.960587, 0.524203,
                 0.954529, 0.965896, 0.540361,
                 0.957896, 0.971003, 0.556275,
                 0.961812, 0.975924, 0.571925,
                 0.966249, 0.980678, 0.587206,
                 0.971162, 0.985282, 0.602154,
                 0.976511, 0.989753, 0.616760,
                 0.982257, 0.994109, 0.631017,
                 0.988362, 0.998364, 0.644924} ;
#endif

#define      plasma_num 256
static char *plasma_name = "Plasma" ;
static float plasma_data[3*plasma_num] =
               {0.050383, 0.029803, 0.527975,
                0.063536, 0.028426, 0.533124,
                0.075353, 0.027206, 0.538007,
                0.086222, 0.026125, 0.542658,
                0.096379, 0.025165, 0.547103,
                0.105980, 0.024309, 0.551368,
                0.115124, 0.023556, 0.555468,
                0.123903, 0.022878, 0.559423,
                0.132381, 0.022258, 0.563250,
                0.140603, 0.021687, 0.566959,
                0.148607, 0.021154, 0.570562,
                0.156421, 0.020651, 0.574065,
                0.164070, 0.020171, 0.577478,
                0.171574, 0.019706, 0.580806,
                0.178950, 0.019252, 0.584054,
                0.186213, 0.018803, 0.587228,
                0.193374, 0.018354, 0.590330,
                0.200445, 0.017902, 0.593364,
                0.207435, 0.017442, 0.596333,
                0.214350, 0.016973, 0.599239,
                0.221197, 0.016497, 0.602083,
                0.227983, 0.016007, 0.604867,
                0.234715, 0.015502, 0.607592,
                0.241396, 0.014979, 0.610259,
                0.248032, 0.014439, 0.612868,
                0.254627, 0.013882, 0.615419,
                0.261183, 0.013308, 0.617911,
                0.267703, 0.012716, 0.620346,
                0.274191, 0.012109, 0.622722,
                0.280648, 0.011488, 0.625038,
                0.287076, 0.010855, 0.627295,
                0.293478, 0.010213, 0.629490,
                0.299855, 0.009561, 0.631624,
                0.306210, 0.008902, 0.633694,
                0.312543, 0.008239, 0.635700,
                0.318856, 0.007576, 0.637640,
                0.325150, 0.006915, 0.639512,
                0.331426, 0.006261, 0.641316,
                0.337683, 0.005618, 0.643049,
                0.343925, 0.004991, 0.644710,
                0.350150, 0.004382, 0.646298,
                0.356359, 0.003798, 0.647810,
                0.362553, 0.003243, 0.649245,
                0.368733, 0.002724, 0.650601,
                0.374897, 0.002245, 0.651876,
                0.381047, 0.001814, 0.653068,
                0.387183, 0.001434, 0.654177,
                0.393304, 0.001114, 0.655199,
                0.399411, 0.000859, 0.656133,
                0.405503, 0.000678, 0.656977,
                0.411580, 0.000577, 0.657730,
                0.417642, 0.000564, 0.658390,
                0.423689, 0.000646, 0.658956,
                0.429719, 0.000831, 0.659425,
                0.435734, 0.001127, 0.659797,
                0.441732, 0.001540, 0.660069,
                0.447714, 0.002080, 0.660240,
                0.453677, 0.002755, 0.660310,
                0.459623, 0.003574, 0.660277,
                0.465550, 0.004545, 0.660139,
                0.471457, 0.005678, 0.659897,
                0.477344, 0.006980, 0.659549,
                0.483210, 0.008460, 0.659095,
                0.489055, 0.010127, 0.658534,
                0.494877, 0.011990, 0.657865,
                0.500678, 0.014055, 0.657088,
                0.506454, 0.016333, 0.656202,
                0.512206, 0.018833, 0.655209,
                0.517933, 0.021563, 0.654109,
                0.523633, 0.024532, 0.652901,
                0.529306, 0.027747, 0.651586,
                0.534952, 0.031217, 0.650165,
                0.540570, 0.034950, 0.648640,
                0.546157, 0.038954, 0.647010,
                0.551715, 0.043136, 0.645277,
                0.557243, 0.047331, 0.643443,
                0.562738, 0.051545, 0.641509,
                0.568201, 0.055778, 0.639477,
                0.573632, 0.060028, 0.637349,
                0.579029, 0.064296, 0.635126,
                0.584391, 0.068579, 0.632812,
                0.589719, 0.072878, 0.630408,
                0.595011, 0.077190, 0.627917,
                0.600266, 0.081516, 0.625342,
                0.605485, 0.085854, 0.622686,
                0.610667, 0.090204, 0.619951,
                0.615812, 0.094564, 0.617140,
                0.620919, 0.098934, 0.614257,
                0.625987, 0.103312, 0.611305,
                0.631017, 0.107699, 0.608287,
                0.636008, 0.112092, 0.605205,
                0.640959, 0.116492, 0.602065,
                0.645872, 0.120898, 0.598867,
                0.650746, 0.125309, 0.595617,
                0.655580, 0.129725, 0.592317,
                0.660374, 0.134144, 0.588971,
                0.665129, 0.138566, 0.585582,
                0.669845, 0.142992, 0.582154,
                0.674522, 0.147419, 0.578688,
                0.679160, 0.151848, 0.575189,
                0.683758, 0.156278, 0.571660,
                0.688318, 0.160709, 0.568103,
                0.692840, 0.165141, 0.564522,
                0.697324, 0.169573, 0.560919,
                0.701769, 0.174005, 0.557296,
                0.706178, 0.178437, 0.553657,
                0.710549, 0.182868, 0.550004,
                0.714883, 0.187299, 0.546338,
                0.719181, 0.191729, 0.542663,
                0.723444, 0.196158, 0.538981,
                0.727670, 0.200586, 0.535293,
                0.731862, 0.205013, 0.531601,
                0.736019, 0.209439, 0.527908,
                0.740143, 0.213864, 0.524216,
                0.744232, 0.218288, 0.520524,
                0.748289, 0.222711, 0.516834,
                0.752312, 0.227133, 0.513149,
                0.756304, 0.231555, 0.509468,
                0.760264, 0.235976, 0.505794,
                0.764193, 0.240396, 0.502126,
                0.768090, 0.244817, 0.498465,
                0.771958, 0.249237, 0.494813,
                0.775796, 0.253658, 0.491171,
                0.779604, 0.258078, 0.487539,
                0.783383, 0.262500, 0.483918,
                0.787133, 0.266922, 0.480307,
                0.790855, 0.271345, 0.476706,
                0.794549, 0.275770, 0.473117,
                0.798216, 0.280197, 0.469538,
                0.801855, 0.284626, 0.465971,
                0.805467, 0.289057, 0.462415,
                0.809052, 0.293491, 0.458870,
                0.812612, 0.297928, 0.455338,
                0.816144, 0.302368, 0.451816,
                0.819651, 0.306812, 0.448306,
                0.823132, 0.311261, 0.444806,
                0.826588, 0.315714, 0.441316,
                0.830018, 0.320172, 0.437836,
                0.833422, 0.324635, 0.434366,
                0.836801, 0.329105, 0.430905,
                0.840155, 0.333580, 0.427455,
                0.843484, 0.338062, 0.424013,
                0.846788, 0.342551, 0.420579,
                0.850066, 0.347048, 0.417153,
                0.853319, 0.351553, 0.413734,
                0.856547, 0.356066, 0.410322,
                0.859750, 0.360588, 0.406917,
                0.862927, 0.365119, 0.403519,
                0.866078, 0.369660, 0.400126,
                0.869203, 0.374212, 0.396738,
                0.872303, 0.378774, 0.393355,
                0.875376, 0.383347, 0.389976,
                0.878423, 0.387932, 0.386600,
                0.881443, 0.392529, 0.383229,
                0.884436, 0.397139, 0.379860,
                0.887402, 0.401762, 0.376494,
                0.890340, 0.406398, 0.373130,
                0.893250, 0.411048, 0.369768,
                0.896131, 0.415712, 0.366407,
                0.898984, 0.420392, 0.363047,
                0.901807, 0.425087, 0.359688,
                0.904601, 0.429797, 0.356329,
                0.907365, 0.434524, 0.352970,
                0.910098, 0.439268, 0.349610,
                0.912800, 0.444029, 0.346251,
                0.915471, 0.448807, 0.342890,
                0.918109, 0.453603, 0.339529,
                0.920714, 0.458417, 0.336166,
                0.923287, 0.463251, 0.332801,
                0.925825, 0.468103, 0.329435,
                0.928329, 0.472975, 0.326067,
                0.930798, 0.477867, 0.322697,
                0.933232, 0.482780, 0.319325,
                0.935630, 0.487712, 0.315952,
                0.937990, 0.492667, 0.312575,
                0.940313, 0.497642, 0.309197,
                0.942598, 0.502639, 0.305816,
                0.944844, 0.507658, 0.302433,
                0.947051, 0.512699, 0.299049,
                0.949217, 0.517763, 0.295662,
                0.951344, 0.522850, 0.292275,
                0.953428, 0.527960, 0.288883,
                0.955470, 0.533093, 0.285490,
                0.957469, 0.538250, 0.282096,
                0.959424, 0.543431, 0.278701,
                0.961336, 0.548636, 0.275305,
                0.963203, 0.553865, 0.271909,
                0.965024, 0.559118, 0.268513,
                0.966798, 0.564396, 0.265118,
                0.968526, 0.569700, 0.261721,
                0.970205, 0.575028, 0.258325,
                0.971835, 0.580382, 0.254931,
                0.973416, 0.585761, 0.251540,
                0.974947, 0.591165, 0.248151,
                0.976428, 0.596595, 0.244767,
                0.977856, 0.602051, 0.241387,
                0.979233, 0.607532, 0.238013,
                0.980556, 0.613039, 0.234646,
                0.981826, 0.618572, 0.231287,
                0.983041, 0.624131, 0.227937,
                0.984199, 0.629718, 0.224595,
                0.985301, 0.635330, 0.221265,
                0.986345, 0.640969, 0.217948,
                0.987332, 0.646633, 0.214648,
                0.988260, 0.652325, 0.211364,
                0.989128, 0.658043, 0.208100,
                0.989935, 0.663787, 0.204859,
                0.990681, 0.669558, 0.201642,
                0.991365, 0.675355, 0.198453,
                0.991985, 0.681179, 0.195295,
                0.992541, 0.687030, 0.192170,
                0.993032, 0.692907, 0.189084,
                0.993456, 0.698810, 0.186041,
                0.993814, 0.704741, 0.183043,
                0.994103, 0.710698, 0.180097,
                0.994324, 0.716681, 0.177208,
                0.994474, 0.722691, 0.174381,
                0.994553, 0.728728, 0.171622,
                0.994561, 0.734791, 0.168938,
                0.994495, 0.740880, 0.166335,
                0.994355, 0.746995, 0.163821,
                0.994141, 0.753137, 0.161404,
                0.993851, 0.759304, 0.159092,
                0.993482, 0.765499, 0.156891,
                0.993033, 0.771720, 0.154808,
                0.992505, 0.777967, 0.152855,
                0.991897, 0.784239, 0.151042,
                0.991209, 0.790537, 0.149377,
                0.990439, 0.796859, 0.147870,
                0.989587, 0.803205, 0.146529,
                0.988648, 0.809579, 0.145357,
                0.987621, 0.815978, 0.144363,
                0.986509, 0.822401, 0.143557,
                0.985314, 0.828846, 0.142945,
                0.984031, 0.835315, 0.142528,
                0.982653, 0.841812, 0.142303,
                0.981190, 0.848329, 0.142279,
                0.979644, 0.854866, 0.142453,
                0.977995, 0.861432, 0.142808,
                0.976265, 0.868016, 0.143351,
                0.974443, 0.874622, 0.144061,
                0.972530, 0.881250, 0.144923,
                0.970533, 0.887896, 0.145919,
                0.968443, 0.894564, 0.147014,
                0.966271, 0.901249, 0.148180,
                0.964021, 0.907950, 0.149370,
                0.961681, 0.914672, 0.150520,
                0.959276, 0.921407, 0.151566,
                0.956808, 0.928152, 0.152409,
                0.954287, 0.934908, 0.152921,
                0.951726, 0.941671, 0.152925,
                0.949151, 0.948435, 0.152178,
                0.946602, 0.955190, 0.150328,
                0.944152, 0.961916, 0.146861,
                0.941896, 0.968590, 0.140956,
                0.940015, 0.975158, 0.131326} ;

#define      viridis_num 256
static char *viridis_name = "Viridis" ;
static float viridis_data[3*viridis_num] =
                {0.267004, 0.004874, 0.329415,
                 0.268510, 0.009605, 0.335427,
                 0.269944, 0.014625, 0.341379,
                 0.271305, 0.019942, 0.347269,
                 0.272594, 0.025563, 0.353093,
                 0.273809, 0.031497, 0.358853,
                 0.274952, 0.037752, 0.364543,
                 0.276022, 0.044167, 0.370164,
                 0.277018, 0.050344, 0.375715,
                 0.277941, 0.056324, 0.381191,
                 0.278791, 0.062145, 0.386592,
                 0.279566, 0.067836, 0.391917,
                 0.280267, 0.073417, 0.397163,
                 0.280894, 0.078907, 0.402329,
                 0.281446, 0.084320, 0.407414,
                 0.281924, 0.089666, 0.412415,
                 0.282327, 0.094955, 0.417331,
                 0.282656, 0.100196, 0.422160,
                 0.282910, 0.105393, 0.426902,
                 0.283091, 0.110553, 0.431554,
                 0.283197, 0.115680, 0.436115,
                 0.283229, 0.120777, 0.440584,
                 0.283187, 0.125848, 0.444960,
                 0.283072, 0.130895, 0.449241,
                 0.282884, 0.135920, 0.453427,
                 0.282623, 0.140926, 0.457517,
                 0.282290, 0.145912, 0.461510,
                 0.281887, 0.150881, 0.465405,
                 0.281412, 0.155834, 0.469201,
                 0.280868, 0.160771, 0.472899,
                 0.280255, 0.165693, 0.476498,
                 0.279574, 0.170599, 0.479997,
                 0.278826, 0.175490, 0.483397,
                 0.278012, 0.180367, 0.486697,
                 0.277134, 0.185228, 0.489898,
                 0.276194, 0.190074, 0.493001,
                 0.275191, 0.194905, 0.496005,
                 0.274128, 0.199721, 0.498911,
                 0.273006, 0.204520, 0.501721,
                 0.271828, 0.209303, 0.504434,
                 0.270595, 0.214069, 0.507052,
                 0.269308, 0.218818, 0.509577,
                 0.267968, 0.223549, 0.512008,
                 0.266580, 0.228262, 0.514349,
                 0.265145, 0.232956, 0.516599,
                 0.263663, 0.237631, 0.518762,
                 0.262138, 0.242286, 0.520837,
                 0.260571, 0.246922, 0.522828,
                 0.258965, 0.251537, 0.524736,
                 0.257322, 0.256130, 0.526563,
                 0.255645, 0.260703, 0.528312,
                 0.253935, 0.265254, 0.529983,
                 0.252194, 0.269783, 0.531579,
                 0.250425, 0.274290, 0.533103,
                 0.248629, 0.278775, 0.534556,
                 0.246811, 0.283237, 0.535941,
                 0.244972, 0.287675, 0.537260,
                 0.243113, 0.292092, 0.538516,
                 0.241237, 0.296485, 0.539709,
                 0.239346, 0.300855, 0.540844,
                 0.237441, 0.305202, 0.541921,
                 0.235526, 0.309527, 0.542944,
                 0.233603, 0.313828, 0.543914,
                 0.231674, 0.318106, 0.544834,
                 0.229739, 0.322361, 0.545706,
                 0.227802, 0.326594, 0.546532,
                 0.225863, 0.330805, 0.547314,
                 0.223925, 0.334994, 0.548053,
                 0.221989, 0.339161, 0.548752,
                 0.220057, 0.343307, 0.549413,
                 0.218130, 0.347432, 0.550038,
                 0.216210, 0.351535, 0.550627,
                 0.214298, 0.355619, 0.551184,
                 0.212395, 0.359683, 0.551710,
                 0.210503, 0.363727, 0.552206,
                 0.208623, 0.367752, 0.552675,
                 0.206756, 0.371758, 0.553117,
                 0.204903, 0.375746, 0.553533,
                 0.203063, 0.379716, 0.553925,
                 0.201239, 0.383670, 0.554294,
                 0.199430, 0.387607, 0.554642,
                 0.197636, 0.391528, 0.554969,
                 0.195860, 0.395433, 0.555276,
                 0.194100, 0.399323, 0.555565,
                 0.192357, 0.403199, 0.555836,
                 0.190631, 0.407061, 0.556089,
                 0.188923, 0.410910, 0.556326,
                 0.187231, 0.414746, 0.556547,
                 0.185556, 0.418570, 0.556753,
                 0.183898, 0.422383, 0.556944,
                 0.182256, 0.426184, 0.557120,
                 0.180629, 0.429975, 0.557282,
                 0.179019, 0.433756, 0.557430,
                 0.177423, 0.437527, 0.557565,
                 0.175841, 0.441290, 0.557685,
                 0.174274, 0.445044, 0.557792,
                 0.172719, 0.448791, 0.557885,
                 0.171176, 0.452530, 0.557965,
                 0.169646, 0.456262, 0.558030,
                 0.168126, 0.459988, 0.558082,
                 0.166617, 0.463708, 0.558119,
                 0.165117, 0.467423, 0.558141,
                 0.163625, 0.471133, 0.558148,
                 0.162142, 0.474838, 0.558140,
                 0.160665, 0.478540, 0.558115,
                 0.159194, 0.482237, 0.558073,
                 0.157729, 0.485932, 0.558013,
                 0.156270, 0.489624, 0.557936,
                 0.154815, 0.493313, 0.557840,
                 0.153364, 0.497000, 0.557724,
                 0.151918, 0.500685, 0.557587,
                 0.150476, 0.504369, 0.557430,
                 0.149039, 0.508051, 0.557250,
                 0.147607, 0.511733, 0.557049,
                 0.146180, 0.515413, 0.556823,
                 0.144759, 0.519093, 0.556572,
                 0.143343, 0.522773, 0.556295,
                 0.141935, 0.526453, 0.555991,
                 0.140536, 0.530132, 0.555659,
                 0.139147, 0.533812, 0.555298,
                 0.137770, 0.537492, 0.554906,
                 0.136408, 0.541173, 0.554483,
                 0.135066, 0.544853, 0.554029,
                 0.133743, 0.548535, 0.553541,
                 0.132444, 0.552216, 0.553018,
                 0.131172, 0.555899, 0.552459,
                 0.129933, 0.559582, 0.551864,
                 0.128729, 0.563265, 0.551229,
                 0.127568, 0.566949, 0.550556,
                 0.126453, 0.570633, 0.549841,
                 0.125394, 0.574318, 0.549086,
                 0.124395, 0.578002, 0.548287,
                 0.123463, 0.581687, 0.547445,
                 0.122606, 0.585371, 0.546557,
                 0.121831, 0.589055, 0.545623,
                 0.121148, 0.592739, 0.544641,
                 0.120565, 0.596422, 0.543611,
                 0.120092, 0.600104, 0.542530,
                 0.119738, 0.603785, 0.541400,
                 0.119512, 0.607464, 0.540218,
                 0.119423, 0.611141, 0.538982,
                 0.119483, 0.614817, 0.537692,
                 0.119699, 0.618490, 0.536347,
                 0.120081, 0.622161, 0.534946,
                 0.120638, 0.625828, 0.533488,
                 0.121380, 0.629492, 0.531973,
                 0.122312, 0.633153, 0.530398,
                 0.123444, 0.636809, 0.528763,
                 0.124780, 0.640461, 0.527068,
                 0.126326, 0.644107, 0.525311,
                 0.128087, 0.647749, 0.523491,
                 0.130067, 0.651384, 0.521608,
                 0.132268, 0.655014, 0.519661,
                 0.134692, 0.658636, 0.517649,
                 0.137339, 0.662252, 0.515571,
                 0.140210, 0.665859, 0.513427,
                 0.143303, 0.669459, 0.511215,
                 0.146616, 0.673050, 0.508936,
                 0.150148, 0.676631, 0.506589,
                 0.153894, 0.680203, 0.504172,
                 0.157851, 0.683765, 0.501686,
                 0.162016, 0.687316, 0.499129,
                 0.166383, 0.690856, 0.496502,
                 0.170948, 0.694384, 0.493803,
                 0.175707, 0.697900, 0.491033,
                 0.180653, 0.701402, 0.488189,
                 0.185783, 0.704891, 0.485273,
                 0.191090, 0.708366, 0.482284,
                 0.196571, 0.711827, 0.479221,
                 0.202219, 0.715272, 0.476084,
                 0.208030, 0.718701, 0.472873,
                 0.214000, 0.722114, 0.469588,
                 0.220124, 0.725509, 0.466226,
                 0.226397, 0.728888, 0.462789,
                 0.232815, 0.732247, 0.459277,
                 0.239374, 0.735588, 0.455688,
                 0.246070, 0.738910, 0.452024,
                 0.252899, 0.742211, 0.448284,
                 0.259857, 0.745492, 0.444467,
                 0.266941, 0.748751, 0.440573,
                 0.274149, 0.751988, 0.436601,
                 0.281477, 0.755203, 0.432552,
                 0.288921, 0.758394, 0.428426,
                 0.296479, 0.761561, 0.424223,
                 0.304148, 0.764704, 0.419943,
                 0.311925, 0.767822, 0.415586,
                 0.319809, 0.770914, 0.411152,
                 0.327796, 0.773980, 0.406640,
                 0.335885, 0.777018, 0.402049,
                 0.344074, 0.780029, 0.397381,
                 0.352360, 0.783011, 0.392636,
                 0.360741, 0.785964, 0.387814,
                 0.369214, 0.788888, 0.382914,
                 0.377779, 0.791781, 0.377939,
                 0.386433, 0.794644, 0.372886,
                 0.395174, 0.797475, 0.367757,
                 0.404001, 0.800275, 0.362552,
                 0.412913, 0.803041, 0.357269,
                 0.421908, 0.805774, 0.351910,
                 0.430983, 0.808473, 0.346476,
                 0.440137, 0.811138, 0.340967,
                 0.449368, 0.813768, 0.335384,
                 0.458674, 0.816363, 0.329727,
                 0.468053, 0.818921, 0.323998,
                 0.477504, 0.821444, 0.318195,
                 0.487026, 0.823929, 0.312321,
                 0.496615, 0.826376, 0.306377,
                 0.506271, 0.828786, 0.300362,
                 0.515992, 0.831158, 0.294279,
                 0.525776, 0.833491, 0.288127,
                 0.535621, 0.835785, 0.281908,
                 0.545524, 0.838039, 0.275626,
                 0.555484, 0.840254, 0.269281,
                 0.565498, 0.842430, 0.262877,
                 0.575563, 0.844566, 0.256415,
                 0.585678, 0.846661, 0.249897,
                 0.595839, 0.848717, 0.243329,
                 0.606045, 0.850733, 0.236712,
                 0.616293, 0.852709, 0.230052,
                 0.626579, 0.854645, 0.223353,
                 0.636902, 0.856542, 0.216620,
                 0.647257, 0.858400, 0.209861,
                 0.657642, 0.860219, 0.203082,
                 0.668054, 0.861999, 0.196293,
                 0.678489, 0.863742, 0.189503,
                 0.688944, 0.865448, 0.182725,
                 0.699415, 0.867117, 0.175971,
                 0.709898, 0.868751, 0.169257,
                 0.720391, 0.870350, 0.162603,
                 0.730889, 0.871916, 0.156029,
                 0.741388, 0.873449, 0.149561,
                 0.751884, 0.874951, 0.143228,
                 0.762373, 0.876424, 0.137064,
                 0.772852, 0.877868, 0.131109,
                 0.783315, 0.879285, 0.125405,
                 0.793760, 0.880678, 0.120005,
                 0.804182, 0.882046, 0.114965,
                 0.814576, 0.883393, 0.110347,
                 0.824940, 0.884720, 0.106217,
                 0.835270, 0.886029, 0.102646,
                 0.845561, 0.887322, 0.099702,
                 0.855810, 0.888601, 0.097452,
                 0.866013, 0.889868, 0.095953,
                 0.876168, 0.891125, 0.095250,
                 0.886271, 0.892374, 0.095374,
                 0.896320, 0.893616, 0.096335,
                 0.906311, 0.894855, 0.098125,
                 0.916242, 0.896091, 0.100717,
                 0.926106, 0.897330, 0.104071,
                 0.935904, 0.898570, 0.108131,
                 0.945636, 0.899815, 0.112838,
                 0.955300, 0.901065, 0.118128,
                 0.964894, 0.902323, 0.123941,
                 0.974417, 0.903590, 0.130215,
                 0.983868, 0.904867, 0.136897,
                 0.993248, 0.906157, 0.143936} ;

/*
  [RWC: 21 Aug 2019 - Google Turbo colors]
  https://gist.github.com/mikhailov-work/6a308c20e494d9e0ccc29036b28faa7a
  https://ai.googleblog.com/2019/08/turbo-improved-rainbow-colormap-for.html
*/

#define      googleturbo_num 256
static char *googleturbo_name = "GoogleTurbo" ;
static float googleturbo_data[3*googleturbo_num] = {
    0.18995,0.07176,0.23217,
    0.19483,0.08339,0.26149,
    0.19956,0.09498,0.29024,
    0.20415, 0.10652, 0.31844,
    0.20860, 0.11802, 0.34607,
    0.21291, 0.12947, 0.37314,
    0.21708, 0.14087, 0.39964,
    0.22111, 0.15223, 0.42558,
    0.22500, 0.16354, 0.45096,
    0.22875, 0.17481, 0.47578,
    0.23236, 0.18603, 0.50004,
    0.23582, 0.19720, 0.52373,
    0.23915, 0.20833, 0.54686,
    0.24234, 0.21941, 0.56942,
    0.24539, 0.23044, 0.59142,
    0.24830, 0.24143, 0.61286,
    0.25107, 0.25237, 0.63374,
    0.25369, 0.26327, 0.65406,
    0.25618, 0.27412, 0.67381,
    0.25853, 0.28492, 0.69300,
    0.26074, 0.29568, 0.71162,
    0.26280, 0.30639, 0.72968,
    0.26473, 0.31706, 0.74718,
    0.26652, 0.32768, 0.76412,
    0.26816, 0.33825, 0.78050,
    0.26967, 0.34878, 0.79631,
    0.27103, 0.35926, 0.81156,
    0.27226, 0.36970, 0.82624,
    0.27334, 0.38008, 0.84037,
    0.27429, 0.39043, 0.85393,
    0.27509, 0.40072, 0.86692,
    0.27576, 0.41097, 0.87936,
    0.27628, 0.42118, 0.89123,
    0.27667, 0.43134, 0.90254,
    0.27691, 0.44145, 0.91328,
    0.27701, 0.45152, 0.92347,
    0.27698, 0.46153, 0.93309,
    0.27680, 0.47151, 0.94214,
    0.27648, 0.48144, 0.95064,
    0.27603, 0.49132, 0.95857,
    0.27543, 0.50115, 0.96594,
    0.27469, 0.51094, 0.97275,
    0.27381, 0.52069, 0.97899,
    0.27273, 0.53040, 0.98461,
    0.27106, 0.54015, 0.98930,
    0.26878, 0.54995, 0.99303,
    0.26592, 0.55979, 0.99583,
    0.26252, 0.56967, 0.99773,
    0.25862, 0.57958, 0.99876,
    0.25425, 0.58950, 0.99896,
    0.24946, 0.59943, 0.99835,
    0.24427, 0.60937, 0.99697,
    0.23874, 0.61931, 0.99485,
    0.23288, 0.62923, 0.99202,
    0.22676, 0.63913, 0.98851,
    0.22039, 0.64901, 0.98436,
    0.21382, 0.65886, 0.97959,
    0.20708, 0.66866, 0.97423,
    0.20021, 0.67842, 0.96833,
    0.19326, 0.68812, 0.96190,
    0.18625, 0.69775, 0.95498,
    0.17923, 0.70732, 0.94761,
    0.17223, 0.71680, 0.93981,
    0.16529, 0.72620, 0.93161,
    0.15844, 0.73551, 0.92305,
    0.15173, 0.74472, 0.91416,
    0.14519, 0.75381, 0.90496,
    0.13886, 0.76279, 0.89550,
    0.13278, 0.77165, 0.88580,
    0.12698, 0.78037, 0.87590,
    0.12151, 0.78896, 0.86581,
    0.11639, 0.79740, 0.85559,
    0.11167, 0.80569, 0.84525,
    0.10738, 0.81381, 0.83484,
    0.10357, 0.82177, 0.82437,
    0.10026, 0.82955, 0.81389,
    0.09750, 0.83714, 0.80342,
    0.09532, 0.84455, 0.79299,
    0.09377, 0.85175, 0.78264,
    0.09287, 0.85875, 0.77240,
    0.09267, 0.86554, 0.76230,
    0.09320, 0.87211, 0.75237,
    0.09451, 0.87844, 0.74265,
    0.09662, 0.88454, 0.73316,
    0.09958, 0.89040, 0.72393,
    0.10342, 0.89600, 0.71500,
    0.10815, 0.90142, 0.70599,
    0.11374, 0.90673, 0.69651,
    0.12014, 0.91193, 0.68660,
    0.12733, 0.91701, 0.67627,
    0.13526, 0.92197, 0.66556,
    0.14391, 0.92680, 0.65448,
    0.15323, 0.93151, 0.64308,
    0.16319, 0.93609, 0.63137,
    0.17377, 0.94053, 0.61938,
    0.18491, 0.94484, 0.60713,
    0.19659, 0.94901, 0.59466,
    0.20877, 0.95304, 0.58199,
    0.22142, 0.95692, 0.56914,
    0.23449, 0.96065, 0.55614,
    0.24797, 0.96423, 0.54303,
    0.26180, 0.96765, 0.52981,
    0.27597, 0.97092, 0.51653,
    0.29042, 0.97403, 0.50321,
    0.30513, 0.97697, 0.48987,
    0.32006, 0.97974, 0.47654,
    0.33517, 0.98234, 0.46325,
    0.35043, 0.98477, 0.45002,
    0.36581, 0.98702, 0.43688,
    0.38127, 0.98909, 0.42386,
    0.39678, 0.99098, 0.41098,
    0.41229, 0.99268, 0.39826,
    0.42778, 0.99419, 0.38575,
    0.44321, 0.99551, 0.37345,
    0.45854, 0.99663, 0.36140,
    0.47375, 0.99755, 0.34963,
    0.48879, 0.99828, 0.33816,
    0.50362, 0.99879, 0.32701,
    0.51822, 0.99910, 0.31622,
    0.53255, 0.99919, 0.30581,
    0.54658, 0.99907, 0.29581,
    0.56026, 0.99873, 0.28623,
    0.57357, 0.99817, 0.27712,
    0.58646, 0.99739, 0.26849,
    0.59891, 0.99638, 0.26038,
    0.61088, 0.99514, 0.25280,
    0.62233, 0.99366, 0.24579,
    0.63323, 0.99195, 0.23937,
    0.64362, 0.98999, 0.23356,
    0.65394, 0.98775, 0.22835,
    0.66428, 0.98524, 0.22370,
    0.67462, 0.98246, 0.21960,
    0.68494, 0.97941, 0.21602,
    0.69525, 0.97610, 0.21294,
    0.70553, 0.97255, 0.21032,
    0.71577, 0.96875, 0.20815,
    0.72596, 0.96470, 0.20640,
    0.73610, 0.96043, 0.20504,
    0.74617, 0.95593, 0.20406,
    0.75617, 0.95121, 0.20343,
    0.76608, 0.94627, 0.20311,
    0.77591, 0.94113, 0.20310,
    0.78563, 0.93579, 0.20336,
    0.79524, 0.93025, 0.20386,
    0.80473, 0.92452, 0.20459,
    0.81410, 0.91861, 0.20552,
    0.82333, 0.91253, 0.20663,
    0.83241, 0.90627, 0.20788,
    0.84133, 0.89986, 0.20926,
    0.85010, 0.89328, 0.21074,
    0.85868, 0.88655, 0.21230,
    0.86709, 0.87968, 0.21391,
    0.87530, 0.87267, 0.21555,
    0.88331, 0.86553, 0.21719,
    0.89112, 0.85826, 0.21880,
    0.89870, 0.85087, 0.22038,
    0.90605, 0.84337, 0.22188,
    0.91317, 0.83576, 0.22328,
    0.92004, 0.82806, 0.22456,
    0.92666, 0.82025, 0.22570,
    0.93301, 0.81236, 0.22667,
    0.93909, 0.80439, 0.22744,
    0.94489, 0.79634, 0.22800,
    0.95039, 0.78823, 0.22831,
    0.95560, 0.78005, 0.22836,
    0.96049, 0.77181, 0.22811,
    0.96507, 0.76352, 0.22754,
    0.96931, 0.75519, 0.22663,
    0.97323, 0.74682, 0.22536,
    0.97679, 0.73842, 0.22369,
    0.98000, 0.73000, 0.22161,
    0.98289, 0.72140, 0.21918,
    0.98549, 0.71250, 0.21650,
    0.98781, 0.70330, 0.21358,
    0.98986, 0.69382, 0.21043,
    0.99163, 0.68408, 0.20706,
    0.99314, 0.67408, 0.20348,
    0.99438, 0.66386, 0.19971,
    0.99535, 0.65341, 0.19577,
    0.99607, 0.64277, 0.19165,
    0.99654, 0.63193, 0.18738,
    0.99675, 0.62093, 0.18297,
    0.99672, 0.60977, 0.17842,
    0.99644, 0.59846, 0.17376,
    0.99593, 0.58703, 0.16899,
    0.99517, 0.57549, 0.16412,
    0.99419, 0.56386, 0.15918,
    0.99297, 0.55214, 0.15417,
    0.99153, 0.54036, 0.14910,
    0.98987, 0.52854, 0.14398,
    0.98799, 0.51667, 0.13883,
    0.98590, 0.50479, 0.13367,
    0.98360, 0.49291, 0.12849,
    0.98108, 0.48104, 0.12332,
    0.97837, 0.46920, 0.11817,
    0.97545, 0.45740, 0.11305,
    0.97234, 0.44565, 0.10797,
    0.96904, 0.43399, 0.10294,
    0.96555, 0.42241, 0.09798,
    0.96187, 0.41093, 0.09310,
    0.95801, 0.39958, 0.08831,
    0.95398, 0.38836, 0.08362,
    0.94977, 0.37729, 0.07905,
    0.94538, 0.36638, 0.07461,
    0.94084, 0.35566, 0.07031,
    0.93612, 0.34513, 0.06616,
    0.93125, 0.33482, 0.06218,
    0.92623, 0.32473, 0.05837,
    0.92105, 0.31489, 0.05475,
    0.91572, 0.30530, 0.05134,
    0.91024, 0.29599, 0.04814,
    0.90463, 0.28696, 0.04516,
    0.89888, 0.27824, 0.04243,
    0.89298, 0.26981, 0.03993,
    0.88691, 0.26152, 0.03753,
    0.88066, 0.25334, 0.03521,
    0.87422, 0.24526, 0.03297,
    0.86760, 0.23730, 0.03082,
    0.86079, 0.22945, 0.02875,
    0.85380, 0.22170, 0.02677,
    0.84662, 0.21407, 0.02487,
    0.83926, 0.20654, 0.02305,
    0.83172, 0.19912, 0.02131,
    0.82399, 0.19182, 0.01966,
    0.81608, 0.18462, 0.01809,
    0.80799, 0.17753, 0.01660,
    0.79971, 0.17055, 0.01520,
    0.79125, 0.16368, 0.01387,
    0.78260, 0.15693, 0.01264,
    0.77377, 0.15028, 0.01148,
    0.76476, 0.14374, 0.01041,
    0.75556, 0.13731, 0.00942,
    0.74617, 0.13098, 0.00851,
    0.73661, 0.12477, 0.00769,
    0.72686, 0.11867, 0.00695,
    0.71692, 0.11268, 0.00629,
    0.70680, 0.10680, 0.00571,
    0.69650, 0.10102, 0.00522,
    0.68602, 0.09536, 0.00481,
    0.67535, 0.08980, 0.00449,
    0.66449, 0.08436, 0.00424,
    0.65345, 0.07902, 0.00408,
    0.64223, 0.07380, 0.00401,
    0.63082, 0.06868, 0.00401,
    0.61923, 0.06367, 0.00410,
    0.60746, 0.05878, 0.00427,
    0.59550, 0.05399, 0.00453,
    0.58336, 0.04931, 0.00486,
    0.57103, 0.04474, 0.00529,
    0.55852, 0.04028, 0.00579,
    0.54583, 0.03593, 0.00638,
    0.53295, 0.03169, 0.00705,
    0.51989, 0.02756, 0.00780,
    0.50664, 0.02354, 0.00863,
    0.49321, 0.01963, 0.00955,
    0.47960, 0.01583, 0.01055
} ;

/*
  [PT: May 28, 2019] Some new colormaps for ROIs, namely the
  GLASBEY colormaps, from here:

    https://github.com/taketwo/glasbey
    http://colorcet.pyviz.org/user_guide/Categorical.html

  For 256, 512, 1024 and 2048 colors.  For Ncolor > 256, one is
  assumed to be using the "-XXXnpane .." opt in afni.
*/
static char ROI_glasbey_256_CMD[] = {
"ROI_glasbey_256 "
"#00008f "
"#b60000 "
"#008c00 "
"#c34fff "
"#01a5ca "
"#ec9d00 "
"#76ff00 "
"#595354 "
"#ff7598 "
"#940073 "
"#00f3cc "
"#4853ff "
"#a6a19a "
"#004301 "
"#edb7ff "
"#8a6800 "
"#6100a3 "
"#5c0011 "
"#fff585 "
"#007b69 "
"#92b853 "
"#abd4ff "
"#7e79a3 "
"#ff5401 "
"#0a577d "
"#a8615c "
"#e700b9 "
"#ffc3a6 "
"#5b3500 "
"#00b485 "
"#7e9eff "
"#e7025c "
"#b8d8b7 "
"#c082b7 "
"#6f895b "
"#8a48a2 "
"#5b325a "
"#dc8a67 "
"#4f5c2c "
"#00e173 "
"#ff68ff "
"#7ec1c1 "
"#783a3d "
"#b7fcff "
"#8809ff "
"#6f8c90 "
"#aca8cc "
"#944305 "
"#00504a "
"#0100fa "
"#565194 "
"#cad800 "
"#097bc0 "
"#b0ff9b "
"#ad934b "
"#c46800 "
"#dacbd7 "
"#00ba00 "
"#ad5289 "
"#837772 "
"#9c003b "
"#906efe "
"#d5c373 "
"#feaccb "
"#00e9ff "
"#c192ff "
"#828e00 "
"#640041 "
"#576878 "
"#7d5e78 "
"#007134 "
"#7a5a3b "
"#352e77 "
"#d14839 "
"#5700e3 "
"#8ab28f "
"#be00cd "
"#821700 "
"#f4eac1 "
"#0f8395 "
"#ffc917 "
"#b8868c "
"#48c6ff "
"#596d5f "
"#c20076 "
"#fdff00 "
"#43485f "
"#7b99bd "
"#750084 "
"#587202 "
"#4ea34f "
"#c3af00 "
"#09a29d "
"#bdd4d9 "
"#abffd6 "
"#7ed200 "
"#d15a77 "
"#ff0022 "
"#ff5cc2 "
"#a17244 "
"#4980ff "
"#a06dbc "
"#d7d1ff "
"#a33b36 "
"#c8a5bc "
"#ff842b "
"#9b8da0 "
"#cbbfa6 "
"#d05ace "
"#0556b8 "
"#fe5c59 "
"#74d4a2 "
"#686bc4 "
"#843f66 "
"#00a1fc "
"#099363 "
"#ef94dd "
"#1e5532 "
"#b6d975 "
"#a800ef "
"#feab63 "
"#ff9f96 "
"#97a9b2 "
"#ff1695 "
"#006770 "
"#978ed4 "
"#695000 "
"#52ffaa "
"#aab8ff "
"#3c4300 "
"#55482d "
"#2f5b00 "
"#50006c "
"#ffd8ff "
"#632511 "
"#003b71 "
"#d2a398 "
"#639b84 "
"#00ceb4 "
"#674b7a "
"#97e0d1 "
"#a0728f "
"#8759ca "
"#dcffc7 "
"#e0ecff "
"#5e7ea1 "
"#adae7b "
"#948d6e "
"#726f3e "
"#8502be "
"#c3fc53 "
"#ffe2df "
"#425558 "
"#d5f2e5 "
"#00c3d7 "
"#dc8caa "
"#a5395d "
"#c10939 "
"#825759 "
"#3300bb "
"#bc4800 "
"#c76a47 "
"#9a00a2 "
"#446597 "
"#c68500 "
"#8db7d9 "
"#acbcb3 "
"#d0a46e "
"#d165a4 "
"#c99eda "
"#60c170 "
"#771934 "
"#fb00f4 "
"#74a905 "
"#503371 "
"#45853e "
"#674656 "
"#d37ee9 "
"#84eb64 "
"#b42498 "
"#8b9c51 "
"#777a85 "
"#59fff9 "
"#98deef "
"#ffd98a "
"#764021 "
"#dc797c "
"#6aa6b2 "
"#435241 "
"#7087ce "
"#6b39b5 "
"#9f8204 "
"#676286 "
"#d8d9d0 "
"#4e7778 "
"#b5886b "
"#ab52ad "
"#b7b3bb "
"#cab2fe "
"#7651fd "
"#b9c3dc "
"#41007e "
"#306354 "
"#3940a1 "
"#fa4b79 "
"#788679 "
"#a05d0d "
"#d91b00 "
"#ff7d5a "
"#00ea29 "
"#642c43 "
"#98c887 "
"#7a387c "
"#eabbbf "
"#e0d85c "
"#92503a "
"#dbe399 "
"#528369 "
"#d53e8c "
"#016f94 "
"#ceb9dd "
"#836398 "
"#db06fb "
"#5e025b "
"#4b7146 "
"#ab76eb "
"#899d95 "
"#4891c6 "
"#a6bf00 "
"#004b5b "
"#5a4bca "
"#9fe8a9 "
"#a688bc "
"#dd9041 "
"#605e48 "
"#74235e "
"#8b8342 "
"#5bb2a1 "
"#cca643 "
"#694940 "
"#6d666d "
"#7ab6fe "
"#a59c24 "
"#bf4253 "
"#227300 "
"#e36d27 "
"#46e1d9 "
"#9b556b "
"#9b0018 "
"#394d7d "
"#5c5467 "
"#8790a0 "
"#8f5087 "
"#8d2254 "
"#f5e9f8 "
"#fe83c1 "
};

static char ROI_glasbey_512_CMD[] = {
"ROI_glasbey_512 "
"#00008f "
"#b60000 "
"#008c00 "
"#c34fff "
"#01a5ca "
"#ec9d00 "
"#76ff00 "
"#595354 "
"#ff7598 "
"#940073 "
"#00f3cc "
"#4853ff "
"#a6a19a "
"#004301 "
"#edb7ff "
"#8a6800 "
"#6100a3 "
"#5c0011 "
"#fff585 "
"#007b69 "
"#92b853 "
"#abd4ff "
"#7e79a3 "
"#ff5401 "
"#0a577d "
"#a8615c "
"#e700b9 "
"#ffc3a6 "
"#5b3500 "
"#00b485 "
"#7e9eff "
"#e7025c "
"#b8d8b7 "
"#c082b7 "
"#6f895b "
"#8a48a2 "
"#5b325a "
"#dc8a67 "
"#4f5c2c "
"#00e173 "
"#ff68ff "
"#7ec1c1 "
"#783a3d "
"#b7fcff "
"#8809ff "
"#6f8c90 "
"#aca8cc "
"#944305 "
"#00504a "
"#0100fa "
"#565194 "
"#cad800 "
"#097bc0 "
"#b0ff9b "
"#ad934b "
"#c46800 "
"#dacbd7 "
"#00ba00 "
"#ad5289 "
"#837772 "
"#9c003b "
"#906efe "
"#d5c373 "
"#feaccb "
"#00e9ff "
"#c192ff "
"#828e00 "
"#640041 "
"#576878 "
"#7d5e78 "
"#007134 "
"#7a5a3b "
"#352e77 "
"#d14839 "
"#5700e3 "
"#8ab28f "
"#be00cd "
"#821700 "
"#f4eac1 "
"#0f8395 "
"#ffc917 "
"#b8868c "
"#48c6ff "
"#596d5f "
"#c20076 "
"#fdff00 "
"#43485f "
"#7b99bd "
"#750084 "
"#587202 "
"#4ea34f "
"#c3af00 "
"#09a29d "
"#bdd4d9 "
"#abffd6 "
"#7ed200 "
"#d15a77 "
"#ff0022 "
"#ff5cc2 "
"#a17244 "
"#4980ff "
"#a06dbc "
"#d7d1ff "
"#a33b36 "
"#c8a5bc "
"#ff842b "
"#9b8da0 "
"#cbbfa6 "
"#d05ace "
"#0556b8 "
"#fe5c59 "
"#74d4a2 "
"#686bc4 "
"#843f66 "
"#00a1fc "
"#099363 "
"#ef94dd "
"#1e5532 "
"#b6d975 "
"#a800ef "
"#feab63 "
"#ff9f96 "
"#97a9b2 "
"#ff1695 "
"#006770 "
"#978ed4 "
"#695000 "
"#52ffaa "
"#aab8ff "
"#3c4300 "
"#55482d "
"#2f5b00 "
"#50006c "
"#ffd8ff "
"#632511 "
"#003b71 "
"#d2a398 "
"#639b84 "
"#00ceb4 "
"#674b7a "
"#97e0d1 "
"#a0728f "
"#8759ca "
"#dcffc7 "
"#e0ecff "
"#5e7ea1 "
"#adae7b "
"#948d6e "
"#726f3e "
"#8502be "
"#c3fc53 "
"#ffe2df "
"#425558 "
"#d5f2e5 "
"#00c3d7 "
"#dc8caa "
"#a5395d "
"#c10939 "
"#825759 "
"#3300bb "
"#bc4800 "
"#c76a47 "
"#9a00a2 "
"#446597 "
"#c68500 "
"#8db7d9 "
"#acbcb3 "
"#d0a46e "
"#d165a4 "
"#c99eda "
"#60c170 "
"#771934 "
"#fb00f4 "
"#74a905 "
"#503371 "
"#45853e "
"#674656 "
"#d37ee9 "
"#84eb64 "
"#b42498 "
"#8b9c51 "
"#777a85 "
"#59fff9 "
"#98deef "
"#ffd98a "
"#764021 "
"#dc797c "
"#6aa6b2 "
"#435241 "
"#7087ce "
"#6b39b5 "
"#9f8204 "
"#676286 "
"#d8d9d0 "
"#4e7778 "
"#b5886b "
"#ab52ad "
"#b7b3bb "
"#cab2fe "
"#7651fd "
"#b9c3dc "
"#41007e "
"#306354 "
"#3940a1 "
"#fa4b79 "
"#788679 "
"#a05d0d "
"#d91b00 "
"#ff7d5a "
"#00ea29 "
"#642c43 "
"#98c887 "
"#7a387c "
"#eabbbf "
"#e0d85c "
"#92503a "
"#dbe399 "
"#528369 "
"#d53e8c "
"#016f94 "
"#ceb9dd "
"#836398 "
"#db06fb "
"#5e025b "
"#4b7146 "
"#ab76eb "
"#899d95 "
"#4891c6 "
"#a6bf00 "
"#004b5b "
"#5a4bca "
"#9fe8a9 "
"#a688bc "
"#dd9041 "
"#605e48 "
"#74235e "
"#8b8342 "
"#5bb2a1 "
"#cca643 "
"#694940 "
"#6d666d "
"#7ab6fe "
"#a59c24 "
"#bf4253 "
"#227300 "
"#e36d27 "
"#46e1d9 "
"#9b556b "
"#9b0018 "
"#394d7d "
"#5c5467 "
"#8790a0 "
"#8f5087 "
"#8d2254 "
"#f5e9f8 "
"#fe83c1 "
"#3639e8 "
"#6c358f "
"#4c09ac "
"#f1b84c "
"#a54cff "
"#b76d7f "
"#5a941b "
"#a0776f "
"#006feb "
"#9e2b00 "
"#00ff77 "
"#7a7813 "
"#5490a6 "
"#a79fff "
"#e474ce "
"#c17d41 "
"#8875c8 "
"#882929 "
"#50cb47 "
"#3f8c82 "
"#825112 "
"#ea98ff "
"#72a16d "
"#9b8a8a "
"#92c7b2 "
"#86748d "
"#b25238 "
"#666414 "
"#edbce2 "
"#d5f483 "
"#94a4db "
"#f6e109 "
"#e01235 "
"#72539f "
"#2c0089 "
"#bac054 "
"#c748a9 "
"#5fa8db "
"#bcc893 "
"#de4702 "
"#a4e701 "
"#7b84ff "
"#a84fd0 "
"#7b0017 "
"#ac7417 "
"#f3ffe6 "
"#867053 "
"#8c6b75 "
"#e357ff "
"#00cc8b "
"#00a422 "
"#75c9e3 "
"#8ad166 "
"#ff2351 "
"#e4bd8b "
"#ffcfe1 "
"#b369a4 "
"#4462c2 "
"#00379f "
"#a0c0cc "
"#eca683 "
"#feffb9 "
"#b49e7f "
"#4f3991 "
"#3e586d "
"#00e8a3 "
"#9f3476 "
"#51415f "
"#be766c "
"#ee579a "
"#00b94e "
"#6c8836 "
"#782d00 "
"#756259 "
"#52430b "
"#9693b7 "
"#dc5f5d "
"#95a184 "
"#217d54 "
"#ebd2b9 "
"#fd94ab "
"#660c00 "
"#c1ebff "
"#b9371f "
"#fd8382 "
"#00a083 "
"#92444d "
"#dbc50a "
"#b49aa1 "
"#b60b53 "
"#646fa0 "
"#07b8b6 "
"#82ebc0 "
"#dd7295 "
"#5b6263 "
"#e95c3a "
"#70765e "
"#cab4b3 "
"#e3a2ae "
"#4e78cc "
"#67bc94 "
"#008be7 "
"#b29ddf "
"#88b1a7 "
"#dd7b00 "
"#a028bf "
"#525300 "
"#d721d0 "
"#8a652e "
"#cc2e69 "
"#6e7472 "
"#47758a "
"#b29abb "
"#66272b "
"#8937ce "
"#898c8d "
"#916454 "
"#394d26 "
"#406b24 "
"#00963e "
"#d4d8b2 "
"#444070 "
"#6e13ff "
"#fe9664 "
"#696dff "
"#a19fa8 "
"#ea4bc9 "
"#a086fe "
"#dcfaff "
"#b38ba4 "
"#bd6ad8 "
"#a8ac56 "
"#004c8f "
"#675b2c "
"#5e256f "
"#274764 "
"#de4157 "
"#91af71 "
"#a7d644 "
"#b64f71 "
"#7effe2 "
"#0987b1 "
"#df918b "
"#68481c "
"#69b449 "
"#77dd8a "
"#d496c3 "
"#c37b9d "
"#e3b000 "
"#744a6e "
"#d2d5e4 "
"#ffadf1 "
"#a60065 "
"#8d3b23 "
"#505778 "
"#607534 "
"#64372b "
"#9d3b99 "
"#46a36e "
"#c5c7c9 "
"#7668a9 "
"#5fb4d1 "
"#006743 "
"#e3e9eb "
"#620029 "
"#99a900 "
"#a35f37 "
"#f1ff68 "
"#e1745a "
"#c3eea4 "
"#c20afb "
"#adb19a "
"#5a93ee "
"#0100bc "
"#ff26b9 "
"#3f6041 "
"#609c98 "
"#9a76a3 "
"#19297e "
"#035518 "
"#cf0199 "
"#96a6c2 "
"#cbdcff "
"#bdbbeb "
"#a6c2a1 "
"#009aaa "
"#b886db "
"#00797b "
"#c09705 "
"#0068ad "
"#822599 "
"#00d5fb "
"#c4f0cb "
"#6400c9 "
"#7e0052 "
"#81be2b "
"#74a03d "
"#ef413e "
"#c872ff "
"#42656c "
"#657d8b "
"#53905e "
"#7887b0 "
"#baded2 "
"#7b967a "
"#67dabd "
"#3f559f "
"#ff9a30 "
"#c05955 "
"#744ad0 "
"#cd5c1f "
"#e1b8a4 "
"#86c9ff "
"#e6007c "
"#00b4fc "
"#6d575f "
"#ffc275 "
"#15cdcb "
"#c045d3 "
"#861980 "
"#b5f4e4 "
"#a38555 "
"#942d43 "
"#82f490 "
"#e2ceee "
"#4b4d55 "
"#72009d "
"#0055ec "
"#2b5142 "
"#ffd75f "
"#a0cdca "
"#dbef09 "
"#9c9b66 "
"#99629c "
"#897f88 "
"#825167 "
"#8fecec "
"#69728b "
"#b2ec6c "
"#f16878 "
"#00d300 "
"#f83400 "
"#355c27 "
"#f1ede2 "
"#4b8203 "
"#df7bb3 "
"#25575d "
"#7b324c "
"#41725b "
"#e1a8de "
"#955f80 "
"#ba3885 "
"#63837b "
"#baffbf "
"#8e45fe "
"#c39154 "
};

static char ROI_glasbey_1024_CMD[] = {
"ROI_glasbey_1024 "
"#00008f "
"#b60000 "
"#008c00 "
"#c34fff "
"#01a5ca "
"#ec9d00 "
"#76ff00 "
"#595354 "
"#ff7598 "
"#940073 "
"#00f3cc "
"#4853ff "
"#a6a19a "
"#004301 "
"#edb7ff "
"#8a6800 "
"#6100a3 "
"#5c0011 "
"#fff585 "
"#007b69 "
"#92b853 "
"#abd4ff "
"#7e79a3 "
"#ff5401 "
"#0a577d "
"#a8615c "
"#e700b9 "
"#ffc3a6 "
"#5b3500 "
"#00b485 "
"#7e9eff "
"#e7025c "
"#b8d8b7 "
"#c082b7 "
"#6f895b "
"#8a48a2 "
"#5b325a "
"#dc8a67 "
"#4f5c2c "
"#00e173 "
"#ff68ff "
"#7ec1c1 "
"#783a3d "
"#b7fcff "
"#8809ff "
"#6f8c90 "
"#aca8cc "
"#944305 "
"#00504a "
"#0100fa "
"#565194 "
"#cad800 "
"#097bc0 "
"#b0ff9b "
"#ad934b "
"#c46800 "
"#dacbd7 "
"#00ba00 "
"#ad5289 "
"#837772 "
"#9c003b "
"#906efe "
"#d5c373 "
"#feaccb "
"#00e9ff "
"#c192ff "
"#828e00 "
"#640041 "
"#576878 "
"#7d5e78 "
"#007134 "
"#7a5a3b "
"#352e77 "
"#d14839 "
"#5700e3 "
"#8ab28f "
"#be00cd "
"#821700 "
"#f4eac1 "
"#0f8395 "
"#ffc917 "
"#b8868c "
"#48c6ff "
"#596d5f "
"#c20076 "
"#fdff00 "
"#43485f "
"#7b99bd "
"#750084 "
"#587202 "
"#4ea34f "
"#c3af00 "
"#09a29d "
"#bdd4d9 "
"#abffd6 "
"#7ed200 "
"#d15a77 "
"#ff0022 "
"#ff5cc2 "
"#a17244 "
"#4980ff "
"#a06dbc "
"#d7d1ff "
"#a33b36 "
"#c8a5bc "
"#ff842b "
"#9b8da0 "
"#cbbfa6 "
"#d05ace "
"#0556b8 "
"#fe5c59 "
"#74d4a2 "
"#686bc4 "
"#843f66 "
"#00a1fc "
"#099363 "
"#ef94dd "
"#1e5532 "
"#b6d975 "
"#a800ef "
"#feab63 "
"#ff9f96 "
"#97a9b2 "
"#ff1695 "
"#006770 "
"#978ed4 "
"#695000 "
"#52ffaa "
"#aab8ff "
"#3c4300 "
"#55482d "
"#2f5b00 "
"#50006c "
"#ffd8ff "
"#632511 "
"#003b71 "
"#d2a398 "
"#639b84 "
"#00ceb4 "
"#674b7a "
"#97e0d1 "
"#a0728f "
"#8759ca "
"#dcffc7 "
"#e0ecff "
"#5e7ea1 "
"#adae7b "
"#948d6e "
"#726f3e "
"#8502be "
"#c3fc53 "
"#ffe2df "
"#425558 "
"#d5f2e5 "
"#00c3d7 "
"#dc8caa "
"#a5395d "
"#c10939 "
"#825759 "
"#3300bb "
"#bc4800 "
"#c76a47 "
"#9a00a2 "
"#446597 "
"#c68500 "
"#8db7d9 "
"#acbcb3 "
"#d0a46e "
"#d165a4 "
"#c99eda "
"#60c170 "
"#771934 "
"#fb00f4 "
"#74a905 "
"#503371 "
"#45853e "
"#674656 "
"#d37ee9 "
"#84eb64 "
"#b42498 "
"#8b9c51 "
"#777a85 "
"#59fff9 "
"#98deef "
"#ffd98a "
"#764021 "
"#dc797c "
"#6aa6b2 "
"#435241 "
"#7087ce "
"#6b39b5 "
"#9f8204 "
"#676286 "
"#d8d9d0 "
"#4e7778 "
"#b5886b "
"#ab52ad "
"#b7b3bb "
"#cab2fe "
"#7651fd "
"#b9c3dc "
"#41007e "
"#306354 "
"#3940a1 "
"#fa4b79 "
"#788679 "
"#a05d0d "
"#d91b00 "
"#ff7d5a "
"#00ea29 "
"#642c43 "
"#98c887 "
"#7a387c "
"#eabbbf "
"#e0d85c "
"#92503a "
"#dbe399 "
"#528369 "
"#d53e8c "
"#016f94 "
"#ceb9dd "
"#836398 "
"#db06fb "
"#5e025b "
"#4b7146 "
"#ab76eb "
"#899d95 "
"#4891c6 "
"#a6bf00 "
"#004b5b "
"#5a4bca "
"#9fe8a9 "
"#a688bc "
"#dd9041 "
"#605e48 "
"#74235e "
"#8b8342 "
"#5bb2a1 "
"#cca643 "
"#694940 "
"#6d666d "
"#7ab6fe "
"#a59c24 "
"#bf4253 "
"#227300 "
"#e36d27 "
"#46e1d9 "
"#9b556b "
"#9b0018 "
"#394d7d "
"#5c5467 "
"#8790a0 "
"#8f5087 "
"#8d2254 "
"#f5e9f8 "
"#fe83c1 "
"#3639e8 "
"#6c358f "
"#4c09ac "
"#f1b84c "
"#a54cff "
"#b76d7f "
"#5a941b "
"#a0776f "
"#006feb "
"#9e2b00 "
"#00ff77 "
"#7a7813 "
"#5490a6 "
"#a79fff "
"#e474ce "
"#c17d41 "
"#8875c8 "
"#882929 "
"#50cb47 "
"#3f8c82 "
"#825112 "
"#ea98ff "
"#72a16d "
"#9b8a8a "
"#92c7b2 "
"#86748d "
"#b25238 "
"#666414 "
"#edbce2 "
"#d5f483 "
"#94a4db "
"#f6e109 "
"#e01235 "
"#72539f "
"#2c0089 "
"#bac054 "
"#c748a9 "
"#5fa8db "
"#bcc893 "
"#de4702 "
"#a4e701 "
"#7b84ff "
"#a84fd0 "
"#7b0017 "
"#ac7417 "
"#f3ffe6 "
"#867053 "
"#8c6b75 "
"#e357ff "
"#00cc8b "
"#00a422 "
"#75c9e3 "
"#8ad166 "
"#ff2351 "
"#e4bd8b "
"#ffcfe1 "
"#b369a4 "
"#4462c2 "
"#00379f "
"#a0c0cc "
"#eca683 "
"#feffb9 "
"#b49e7f "
"#4f3991 "
"#3e586d "
"#00e8a3 "
"#9f3476 "
"#51415f "
"#be766c "
"#ee579a "
"#00b94e "
"#6c8836 "
"#782d00 "
"#756259 "
"#52430b "
"#9693b7 "
"#dc5f5d "
"#95a184 "
"#217d54 "
"#ebd2b9 "
"#fd94ab "
"#660c00 "
"#c1ebff "
"#b9371f "
"#fd8382 "
"#00a083 "
"#92444d "
"#dbc50a "
"#b49aa1 "
"#b60b53 "
"#646fa0 "
"#07b8b6 "
"#82ebc0 "
"#dd7295 "
"#5b6263 "
"#e95c3a "
"#70765e "
"#cab4b3 "
"#e3a2ae "
"#4e78cc "
"#67bc94 "
"#008be7 "
"#b29ddf "
"#88b1a7 "
"#dd7b00 "
"#a028bf "
"#525300 "
"#d721d0 "
"#8a652e "
"#cc2e69 "
"#6e7472 "
"#47758a "
"#b29abb "
"#66272b "
"#8937ce "
"#898c8d "
"#916454 "
"#394d26 "
"#406b24 "
"#00963e "
"#d4d8b2 "
"#444070 "
"#6e13ff "
"#fe9664 "
"#696dff "
"#a19fa8 "
"#ea4bc9 "
"#a086fe "
"#dcfaff "
"#b38ba4 "
"#bd6ad8 "
"#a8ac56 "
"#004c8f "
"#675b2c "
"#5e256f "
"#274764 "
"#de4157 "
"#91af71 "
"#a7d644 "
"#b64f71 "
"#7effe2 "
"#0987b1 "
"#df918b "
"#68481c "
"#69b449 "
"#77dd8a "
"#d496c3 "
"#c37b9d "
"#e3b000 "
"#744a6e "
"#d2d5e4 "
"#ffadf1 "
"#a60065 "
"#8d3b23 "
"#505778 "
"#607534 "
"#64372b "
"#9d3b99 "
"#46a36e "
"#c5c7c9 "
"#7668a9 "
"#5fb4d1 "
"#006743 "
"#e3e9eb "
"#620029 "
"#99a900 "
"#a35f37 "
"#f1ff68 "
"#e1745a "
"#c3eea4 "
"#c20afb "
"#adb19a "
"#5a93ee "
"#0100bc "
"#ff26b9 "
"#3f6041 "
"#609c98 "
"#9a76a3 "
"#19297e "
"#035518 "
"#cf0199 "
"#96a6c2 "
"#cbdcff "
"#bdbbeb "
"#a6c2a1 "
"#009aaa "
"#b886db "
"#00797b "
"#c09705 "
"#0068ad "
"#822599 "
"#00d5fb "
"#c4f0cb "
"#6400c9 "
"#7e0052 "
"#81be2b "
"#74a03d "
"#ef413e "
"#c872ff "
"#42656c "
"#657d8b "
"#53905e "
"#7887b0 "
"#baded2 "
"#7b967a "
"#67dabd "
"#3f559f "
"#ff9a30 "
"#c05955 "
"#744ad0 "
"#cd5c1f "
"#e1b8a4 "
"#86c9ff "
"#e6007c "
"#00b4fc "
"#6d575f "
"#ffc275 "
"#15cdcb "
"#c045d3 "
"#861980 "
"#b5f4e4 "
"#a38555 "
"#942d43 "
"#82f490 "
"#e2ceee "
"#4b4d55 "
"#72009d "
"#0055ec "
"#2b5142 "
"#ffd75f "
"#a0cdca "
"#dbef09 "
"#9c9b66 "
"#99629c "
"#897f88 "
"#825167 "
"#8fecec "
"#69728b "
"#b2ec6c "
"#f16878 "
"#00d300 "
"#f83400 "
"#355c27 "
"#f1ede2 "
"#4b8203 "
"#df7bb3 "
"#25575d "
"#7b324c "
"#41725b "
"#e1a8de "
"#955f80 "
"#ba3885 "
"#63837b "
"#baffbf "
"#8e45fe "
"#c39154 "
"#769ddc "
"#e3a653 "
"#6d395a "
"#7797a7 "
"#ae2126 "
"#a6bfeb "
"#4e878e "
"#c1cbb9 "
"#ff89fb "
"#95ff5c "
"#a94e58 "
"#ff0e74 "
"#773122 "
"#e3d196 "
"#5f458a "
"#95752e "
"#3a00e5 "
"#d7be48 "
"#b1d99a "
"#11ba70 "
"#ad2d45 "
"#ac6e55 "
"#ef99c6 "
"#abbe74 "
"#e24077 "
"#554854 "
"#bb9489 "
"#daeacf "
"#76d4db "
"#00802c "
"#918e30 "
"#9f7d88 "
"#723e00 "
"#c8ba87 "
"#675ab0 "
"#915bb5 "
"#b7e6e8 "
"#ffb0b6 "
"#927ab4 "
"#dcc8c4 "
"#add1e6 "
"#9d64d6 "
"#c81a21 "
"#ff6f2f "
"#5e6b4a "
"#dab8cb "
"#ffcdc7 "
"#d58ad3 "
"#633a40 "
"#2b3d7f "
"#ff7ddc "
"#868299 "
"#9bdab6 "
"#d4a1fd "
"#a4411e "
"#c995a3 "
"#e6e1fe "
"#7e65dc "
"#fed3a3 "
"#501a7c "
"#be608a "
"#b45b1b "
"#7e4a40 "
"#84d9ff "
"#495e55 "
"#33aebf "
"#d2e654 "
"#82b5c4 "
"#3f75a1 "
"#80825b "
"#cbad8e "
"#e88246 "
"#cd9879 "
"#2a4b00 "
"#629fbd "
"#73677e "
"#0540c3 "
"#7f00da "
"#ff5be1 "
"#4e6100 "
"#c975ca "
"#7c5287 "
"#6dc5b2 "
"#ffb000 "
"#006b63 "
"#bba561 "
"#701d1a "
"#3d6683 "
"#aab2c4 "
"#929488 "
"#987e65 "
"#dbc1fb "
"#e449a9 "
"#9faaa7 "
"#7979db "
"#785f19 "
"#7fa1a3 "
"#008c71 "
"#56ffc7 "
"#ea099c "
"#9de386 "
"#26ff47 "
"#8d3a7c "
"#5fa6fd "
"#00cc64 "
"#76b47a "
"#607b5a "
"#5738b8 "
"#5f1d4e "
"#679650 "
"#6a8100 "
"#e5ffa9 "
"#7579b8 "
"#bbacc4 "
"#018e91 "
"#006715 "
"#5633ff "
"#beccff "
"#8f92f1 "
"#c4d14a "
"#75006c "
"#adff00 "
"#974b76 "
"#b17abd "
"#67685f "
"#c6c1d2 "
"#525968 "
"#0ad8a8 "
"#c9696f "
"#554b74 "
"#9c1cff "
"#ffc5ff "
"#504e42 "
"#a06772 "
"#e7dee1 "
"#5f3a6f "
"#701d45 "
"#b7b5b0 "
"#c98878 "
"#56df55 "
"#5662a6 "
"#cd8190 "
"#f38f78 "
"#c8d180 "
"#642c00 "
"#5e5dde "
"#8693ca "
"#6caa85 "
"#88003f "
"#7b40a8 "
"#8cc59b "
"#9d1e8b "
"#ff6bad "
"#eb54e7 "
"#78e72c "
"#cb05b3 "
"#afbbc0 "
"#e2a9c9 "
"#a5907e "
"#92fbba "
"#275a92 "
"#b56c39 "
"#b78535 "
"#8d5931 "
"#849666 "
"#035b6f "
"#586688 "
"#4e4e25 "
"#d0284f "
"#794353 "
"#5ac200 "
"#00bae8 "
"#eb8496 "
"#acabe6 "
"#472685 "
"#ecaba1 "
"#ab0080 "
"#c1ace0 "
"#324d5a "
"#91a63d "
"#d49627 "
"#56a62e "
"#5e6f73 "
"#008949 "
"#ffe857 "
"#e6d67c "
"#127385 "
"#15a0dc "
"#466bff "
"#005b45 "
"#e89c62 "
"#768298 "
"#81a6bd "
"#bca599 "
"#c57c5b "
"#486b64 "
"#955553 "
"#5f3c1f "
"#b864bc "
"#f8eb9c "
"#26d6e5 "
"#5883bc "
"#67533d "
"#6e266e "
"#ff00d7 "
"#4225b8 "
"#747e44 "
"#abb136 "
"#a081d0 "
"#b000ae "
"#882a67 "
"#84816e "
"#614963 "
"#cbe5b5 "
"#7aac5d "
"#6d5877 "
"#c2b45d "
"#00bc9e "
"#72eba6 "
"#ec8c07 "
"#736646 "
"#be3bb8 "
"#8f3a58 "
"#89132d "
"#ca3801 "
"#749187 "
"#6fecd8 "
"#636474 "
"#ff4c31 "
"#701faf "
"#91adfc "
"#5eb9c2 "
"#99271d "
"#9a46db "
"#d0e6ee "
"#909a9f "
"#02f38c "
"#404fc2 "
"#a4c857 "
"#7aedff "
"#4c5250 "
"#ed7eff "
"#ffb686 "
"#8f7a4b "
"#5c4649 "
"#479273 "
"#8a86b9 "
"#7f7128 "
"#bc8dc9 "
"#447d70 "
"#4a8053 "
"#6d8ca8 "
"#b0469b "
"#afcdbd "
"#8c688c "
"#bd3438 "
"#758183 "
"#00a358 "
"#f0d7eb "
"#a485a7 "
"#635589 "
"#3e6fb3 "
"#70b8e9 "
"#e5f0b9 "
"#edfff9 "
"#99ad9a "
"#73b0af "
"#5b2f8d "
"#03622d "
"#83acdf "
"#3f5213 "
"#b65d6a "
"#dcffe1 "
"#d8b36c "
"#61d26c "
"#9e1f31 "
"#cca6ad "
"#9cbbb9 "
"#620082 "
"#7e707b "
"#a18435 "
"#c967b6 "
"#d58cff "
"#a96584 "
"#7ed2c8 "
"#8c3200 "
"#214b1d "
"#84be6e "
"#2f2e94 "
"#7acb89 "
"#4ca98b "
"#f57267 "
"#ab8ee8 "
"#ff6747 "
"#884922 "
"#d5588e "
"#a01f52 "
"#40d98a "
"#cc6f31 "
"#bfc022 "
"#454689 "
"#407922 "
"#7e8d4b "
"#a3501e "
"#e13a22 "
"#94c9e9 "
"#20019f "
"#a00e00 "
"#f3bcd2 "
"#f44a5e "
"#0965cb "
"#b4a042 "
"#77438c "
"#ac9028 "
"#cca9d0 "
"#2195b6 "
"#a9ebcb "
"#ffe3ca "
"#fff2f5 "
"#9483a8 "
"#cedcd9 "
"#876b65 "
"#c3791c "
"#76a397 "
"#a24d43 "
"#796c92 "
"#5f6833 "
"#8e82e1 "
"#99fff5 "
"#896ab1 "
"#4c933c "
"#31693c "
"#6a896e "
"#8d5c03 "
"#56af69 "
"#48829f "
"#802c3a "
"#e85f85 "
"#cd51ec "
"#9fb38c "
"#51604a "
"#b7316c "
"#00f1f3 "
"#893b37 "
"#671423 "
"#a39db5 "
"#e5e87f "
"#056e57 "
"#d6aeee "
"#9806d1 "
"#3f5a80 "
"#191bca "
"#9f9cd0 "
"#f67100 "
"#c75839 "
"#e563ba "
"#3c108e "
"#4ea9aa "
"#c1ff7f "
"#efd1d6 "
"#b09464 "
"#78564a "
"#967e93 "
"#ad79a4 "
"#b230fe "
"#734c33 "
"#b230d4 "
"#38783d "
"#f3f5ff "
"#677a6c "
"#a367fe "
"#bca3ff "
"#17ac98 "
"#ef7ea8 "
"#c34e92 "
"#69dbf3 "
"#94d69d "
"#cffff7 "
"#79ff7a "
"#9f48b5 "
"#4539c7 "
"#a8e0ff "
"#b07a8f "
"#539aa4 "
"#701bde "
"#b0a0b0 "
"#a94474 "
"#aa867f "
"#95cdd9 "
"#6b90c4 "
"#e85a00 "
"#8e7711 "
"#b6a9ac "
"#315853 "
"#fea0ff "
"#cac5e6 "
"#e7ad74 "
"#7a6469 "
"#c5d9eb "
"#5e8247 "
"#31416a "
"#86da49 "
"#849e16 "
"#a3b0d8 "
"#b6624d "
"#6b3c6a "
"#4c4aa8 "
"#637ee1 "
"#e371e6 "
"#8c308f "
"#eec76d "
"#5d5b62 "
"#a6f0ff "
"#933fbf "
"#83a48d "
"#685550 "
"#fffed3 "
"#712006 "
"#b54843 "
"#714c51 "
"#5a205b "
"#813c06 "
"#75003b "
"#8b8200 "
"#00ffe6 "
"#c88cad "
"#004975 "
"#97beff "
"#a4bbd5 "
"#ff5d93 "
"#529ce0 "
"#595c55 "
"#786f5f "
"#745524 "
"#af7679 "
"#5fea77 "
"#7e9336 "
"#a58c98 "
"#ffac40 "
"#999597 "
"#916845 "
"#6f2982 "
"#015d59 "
"#9400b5 "
"#5c3c54 "
"#a997c5 "
"#cabbc5 "
"#eecbff "
"#cb4878 "
"#842b14 "
"#9c6805 "
"#b9c0a0 "
"#d5a10a "
"#4d5a8e "
"#6b6e75 "
"#646199 "
"#e039e6 "
"#99dbdc "
"#d60986 "
"#b27b53 "
"#45c7a1 "
"#ffaf96 "
"#651e34 "
"#8d5d6b "
"#59bdb6 "
"#78c353 "
"#ae0239 "
"#6f0356 "
"#7e7d7e "
"#786900 "
"#925eea "
"#b9e540 "
"#be92b9 "
"#51543a "
"#604aab "
"#828c71 "
"#547190 "
"#c9dcca "
"#efc749 "
"#f39246 "
"#b265e5 "
"#bbb6d4 "
"#d593e8 "
"#c29742 "
"#96519d "
"#7a356a "
"#d28851 "
"#a25695 "
"#9f9947 "
"#002fff "
"#5ab423 "
"#891517 "
"#88a57a "
"#9e4487 "
"#dfd72e "
"#00e2c7 "
"#356f6e "
"#008acb "
"#725a8a "
"#7790ea "
"#d635a2 "
"#b03800 "
"#c297e7 "
"#5b5217 "
"#669772 "
"#ce6e5f "
"#f03465 "
"#ff9fdd "
"#e9001b "
"#6e5368 "
"#ab34b4 "
"#c8c4bc "
};


static char ROI_glasbey_2048_CMD[] = {
"ROI_glasbey_2048 "
"#00008f "
"#b60000 "
"#008c00 "
"#c34fff "
"#01a5ca "
"#ec9d00 "
"#76ff00 "
"#595354 "
"#ff7598 "
"#940073 "
"#00f3cc "
"#4853ff "
"#a6a19a "
"#004301 "
"#edb7ff "
"#8a6800 "
"#6100a3 "
"#5c0011 "
"#fff585 "
"#007b69 "
"#92b853 "
"#abd4ff "
"#7e79a3 "
"#ff5401 "
"#0a577d "
"#a8615c "
"#e700b9 "
"#ffc3a6 "
"#5b3500 "
"#00b485 "
"#7e9eff "
"#e7025c "
"#b8d8b7 "
"#c082b7 "
"#6f895b "
"#8a48a2 "
"#5b325a "
"#dc8a67 "
"#4f5c2c "
"#00e173 "
"#ff68ff "
"#7ec1c1 "
"#783a3d "
"#b7fcff "
"#8809ff "
"#6f8c90 "
"#aca8cc "
"#944305 "
"#00504a "
"#0100fa "
"#565194 "
"#cad800 "
"#097bc0 "
"#b0ff9b "
"#ad934b "
"#c46800 "
"#dacbd7 "
"#00ba00 "
"#ad5289 "
"#837772 "
"#9c003b "
"#906efe "
"#d5c373 "
"#feaccb "
"#00e9ff "
"#c192ff "
"#828e00 "
"#640041 "
"#576878 "
"#7d5e78 "
"#007134 "
"#7a5a3b "
"#352e77 "
"#d14839 "
"#5700e3 "
"#8ab28f "
"#be00cd "
"#821700 "
"#f4eac1 "
"#0f8395 "
"#ffc917 "
"#b8868c "
"#48c6ff "
"#596d5f "
"#c20076 "
"#fdff00 "
"#43485f "
"#7b99bd "
"#750084 "
"#587202 "
"#4ea34f "
"#c3af00 "
"#09a29d "
"#bdd4d9 "
"#abffd6 "
"#7ed200 "
"#d15a77 "
"#ff0022 "
"#ff5cc2 "
"#a17244 "
"#4980ff "
"#a06dbc "
"#d7d1ff "
"#a33b36 "
"#c8a5bc "
"#ff842b "
"#9b8da0 "
"#cbbfa6 "
"#d05ace "
"#0556b8 "
"#fe5c59 "
"#74d4a2 "
"#686bc4 "
"#843f66 "
"#00a1fc "
"#099363 "
"#ef94dd "
"#1e5532 "
"#b6d975 "
"#a800ef "
"#feab63 "
"#ff9f96 "
"#97a9b2 "
"#ff1695 "
"#006770 "
"#978ed4 "
"#695000 "
"#52ffaa "
"#aab8ff "
"#3c4300 "
"#55482d "
"#2f5b00 "
"#50006c "
"#ffd8ff "
"#632511 "
"#003b71 "
"#d2a398 "
"#639b84 "
"#00ceb4 "
"#674b7a "
"#97e0d1 "
"#a0728f "
"#8759ca "
"#dcffc7 "
"#e0ecff "
"#5e7ea1 "
"#adae7b "
"#948d6e "
"#726f3e "
"#8502be "
"#c3fc53 "
"#ffe2df "
"#425558 "
"#d5f2e5 "
"#00c3d7 "
"#dc8caa "
"#a5395d "
"#c10939 "
"#825759 "
"#3300bb "
"#bc4800 "
"#c76a47 "
"#9a00a2 "
"#446597 "
"#c68500 "
"#8db7d9 "
"#acbcb3 "
"#d0a46e "
"#d165a4 "
"#c99eda "
"#60c170 "
"#771934 "
"#fb00f4 "
"#74a905 "
"#503371 "
"#45853e "
"#674656 "
"#d37ee9 "
"#84eb64 "
"#b42498 "
"#8b9c51 "
"#777a85 "
"#59fff9 "
"#98deef "
"#ffd98a "
"#764021 "
"#dc797c "
"#6aa6b2 "
"#435241 "
"#7087ce "
"#6b39b5 "
"#9f8204 "
"#676286 "
"#d8d9d0 "
"#4e7778 "
"#b5886b "
"#ab52ad "
"#b7b3bb "
"#cab2fe "
"#7651fd "
"#b9c3dc "
"#41007e "
"#306354 "
"#3940a1 "
"#fa4b79 "
"#788679 "
"#a05d0d "
"#d91b00 "
"#ff7d5a "
"#00ea29 "
"#642c43 "
"#98c887 "
"#7a387c "
"#eabbbf "
"#e0d85c "
"#92503a "
"#dbe399 "
"#528369 "
"#d53e8c "
"#016f94 "
"#ceb9dd "
"#836398 "
"#db06fb "
"#5e025b "
"#4b7146 "
"#ab76eb "
"#899d95 "
"#4891c6 "
"#a6bf00 "
"#004b5b "
"#5a4bca "
"#9fe8a9 "
"#a688bc "
"#dd9041 "
"#605e48 "
"#74235e "
"#8b8342 "
"#5bb2a1 "
"#cca643 "
"#694940 "
"#6d666d "
"#7ab6fe "
"#a59c24 "
"#bf4253 "
"#227300 "
"#e36d27 "
"#46e1d9 "
"#9b556b "
"#9b0018 "
"#394d7d "
"#5c5467 "
"#8790a0 "
"#8f5087 "
"#8d2254 "
"#f5e9f8 "
"#fe83c1 "
"#3639e8 "
"#6c358f "
"#4c09ac "
"#f1b84c "
"#a54cff "
"#b76d7f "
"#5a941b "
"#a0776f "
"#006feb "
"#9e2b00 "
"#00ff77 "
"#7a7813 "
"#5490a6 "
"#a79fff "
"#e474ce "
"#c17d41 "
"#8875c8 "
"#882929 "
"#50cb47 "
"#3f8c82 "
"#825112 "
"#ea98ff "
"#72a16d "
"#9b8a8a "
"#92c7b2 "
"#86748d "
"#b25238 "
"#666414 "
"#edbce2 "
"#d5f483 "
"#94a4db "
"#f6e109 "
"#e01235 "
"#72539f "
"#2c0089 "
"#bac054 "
"#c748a9 "
"#5fa8db "
"#bcc893 "
"#de4702 "
"#a4e701 "
"#7b84ff "
"#a84fd0 "
"#7b0017 "
"#ac7417 "
"#f3ffe6 "
"#867053 "
"#8c6b75 "
"#e357ff "
"#00cc8b "
"#00a422 "
"#75c9e3 "
"#8ad166 "
"#ff2351 "
"#e4bd8b "
"#ffcfe1 "
"#b369a4 "
"#4462c2 "
"#00379f "
"#a0c0cc "
"#eca683 "
"#feffb9 "
"#b49e7f "
"#4f3991 "
"#3e586d "
"#00e8a3 "
"#9f3476 "
"#51415f "
"#be766c "
"#ee579a "
"#00b94e "
"#6c8836 "
"#782d00 "
"#756259 "
"#52430b "
"#9693b7 "
"#dc5f5d "
"#95a184 "
"#217d54 "
"#ebd2b9 "
"#fd94ab "
"#660c00 "
"#c1ebff "
"#b9371f "
"#fd8382 "
"#00a083 "
"#92444d "
"#dbc50a "
"#b49aa1 "
"#b60b53 "
"#646fa0 "
"#07b8b6 "
"#82ebc0 "
"#dd7295 "
"#5b6263 "
"#e95c3a "
"#70765e "
"#cab4b3 "
"#e3a2ae "
"#4e78cc "
"#67bc94 "
"#008be7 "
"#b29ddf "
"#88b1a7 "
"#dd7b00 "
"#a028bf "
"#525300 "
"#d721d0 "
"#8a652e "
"#cc2e69 "
"#6e7472 "
"#47758a "
"#b29abb "
"#66272b "
"#8937ce "
"#898c8d "
"#916454 "
"#394d26 "
"#406b24 "
"#00963e "
"#d4d8b2 "
"#444070 "
"#6e13ff "
"#fe9664 "
"#696dff "
"#a19fa8 "
"#ea4bc9 "
"#a086fe "
"#dcfaff "
"#b38ba4 "
"#bd6ad8 "
"#a8ac56 "
"#004c8f "
"#675b2c "
"#5e256f "
"#274764 "
"#de4157 "
"#91af71 "
"#a7d644 "
"#b64f71 "
"#7effe2 "
"#0987b1 "
"#df918b "
"#68481c "
"#69b449 "
"#77dd8a "
"#d496c3 "
"#c37b9d "
"#e3b000 "
"#744a6e "
"#d2d5e4 "
"#ffadf1 "
"#a60065 "
"#8d3b23 "
"#505778 "
"#607534 "
"#64372b "
"#9d3b99 "
"#46a36e "
"#c5c7c9 "
"#7668a9 "
"#5fb4d1 "
"#006743 "
"#e3e9eb "
"#620029 "
"#99a900 "
"#a35f37 "
"#f1ff68 "
"#e1745a "
"#c3eea4 "
"#c20afb "
"#adb19a "
"#5a93ee "
"#0100bc "
"#ff26b9 "
"#3f6041 "
"#609c98 "
"#9a76a3 "
"#19297e "
"#035518 "
"#cf0199 "
"#96a6c2 "
"#cbdcff "
"#bdbbeb "
"#a6c2a1 "
"#009aaa "
"#b886db "
"#00797b "
"#c09705 "
"#0068ad "
"#822599 "
"#00d5fb "
"#c4f0cb "
"#6400c9 "
"#7e0052 "
"#81be2b "
"#74a03d "
"#ef413e "
"#c872ff "
"#42656c "
"#657d8b "
"#53905e "
"#7887b0 "
"#baded2 "
"#7b967a "
"#67dabd "
"#3f559f "
"#ff9a30 "
"#c05955 "
"#744ad0 "
"#cd5c1f "
"#e1b8a4 "
"#86c9ff "
"#e6007c "
"#00b4fc "
"#6d575f "
"#ffc275 "
"#15cdcb "
"#c045d3 "
"#861980 "
"#b5f4e4 "
"#a38555 "
"#942d43 "
"#82f490 "
"#e2ceee "
"#4b4d55 "
"#72009d "
"#0055ec "
"#2b5142 "
"#ffd75f "
"#a0cdca "
"#dbef09 "
"#9c9b66 "
"#99629c "
"#897f88 "
"#825167 "
"#8fecec "
"#69728b "
"#b2ec6c "
"#f16878 "
"#00d300 "
"#f83400 "
"#355c27 "
"#f1ede2 "
"#4b8203 "
"#df7bb3 "
"#25575d "
"#7b324c "
"#41725b "
"#e1a8de "
"#955f80 "
"#ba3885 "
"#63837b "
"#baffbf "
"#8e45fe "
"#c39154 "
"#769ddc "
"#e3a653 "
"#6d395a "
"#7797a7 "
"#ae2126 "
"#a6bfeb "
"#4e878e "
"#c1cbb9 "
"#ff89fb "
"#95ff5c "
"#a94e58 "
"#ff0e74 "
"#773122 "
"#e3d196 "
"#5f458a "
"#95752e "
"#3a00e5 "
"#d7be48 "
"#b1d99a "
"#11ba70 "
"#ad2d45 "
"#ac6e55 "
"#ef99c6 "
"#abbe74 "
"#e24077 "
"#554854 "
"#bb9489 "
"#daeacf "
"#76d4db "
"#00802c "
"#918e30 "
"#9f7d88 "
"#723e00 "
"#c8ba87 "
"#675ab0 "
"#915bb5 "
"#b7e6e8 "
"#ffb0b6 "
"#927ab4 "
"#dcc8c4 "
"#add1e6 "
"#9d64d6 "
"#c81a21 "
"#ff6f2f "
"#5e6b4a "
"#dab8cb "
"#ffcdc7 "
"#d58ad3 "
"#633a40 "
"#2b3d7f "
"#ff7ddc "
"#868299 "
"#9bdab6 "
"#d4a1fd "
"#a4411e "
"#c995a3 "
"#e6e1fe "
"#7e65dc "
"#fed3a3 "
"#501a7c "
"#be608a "
"#b45b1b "
"#7e4a40 "
"#84d9ff "
"#495e55 "
"#33aebf "
"#d2e654 "
"#82b5c4 "
"#3f75a1 "
"#80825b "
"#cbad8e "
"#e88246 "
"#cd9879 "
"#2a4b00 "
"#629fbd "
"#73677e "
"#0540c3 "
"#7f00da "
"#ff5be1 "
"#4e6100 "
"#c975ca "
"#7c5287 "
"#6dc5b2 "
"#ffb000 "
"#006b63 "
"#bba561 "
"#701d1a "
"#3d6683 "
"#aab2c4 "
"#929488 "
"#987e65 "
"#dbc1fb "
"#e449a9 "
"#9faaa7 "
"#7979db "
"#785f19 "
"#7fa1a3 "
"#008c71 "
"#56ffc7 "
"#ea099c "
"#9de386 "
"#26ff47 "
"#8d3a7c "
"#5fa6fd "
"#00cc64 "
"#76b47a "
"#607b5a "
"#5738b8 "
"#5f1d4e "
"#679650 "
"#6a8100 "
"#e5ffa9 "
"#7579b8 "
"#bbacc4 "
"#018e91 "
"#006715 "
"#5633ff "
"#beccff "
"#8f92f1 "
"#c4d14a "
"#75006c "
"#adff00 "
"#974b76 "
"#b17abd "
"#67685f "
"#c6c1d2 "
"#525968 "
"#0ad8a8 "
"#c9696f "
"#554b74 "
"#9c1cff "
"#ffc5ff "
"#504e42 "
"#a06772 "
"#e7dee1 "
"#5f3a6f "
"#701d45 "
"#b7b5b0 "
"#c98878 "
"#56df55 "
"#5662a6 "
"#cd8190 "
"#f38f78 "
"#c8d180 "
"#642c00 "
"#5e5dde "
"#8693ca "
"#6caa85 "
"#88003f "
"#7b40a8 "
"#8cc59b "
"#9d1e8b "
"#ff6bad "
"#eb54e7 "
"#78e72c "
"#cb05b3 "
"#afbbc0 "
"#e2a9c9 "
"#a5907e "
"#92fbba "
"#275a92 "
"#b56c39 "
"#b78535 "
"#8d5931 "
"#849666 "
"#035b6f "
"#586688 "
"#4e4e25 "
"#d0284f "
"#794353 "
"#5ac200 "
"#00bae8 "
"#eb8496 "
"#acabe6 "
"#472685 "
"#ecaba1 "
"#ab0080 "
"#c1ace0 "
"#324d5a "
"#91a63d "
"#d49627 "
"#56a62e "
"#5e6f73 "
"#008949 "
"#ffe857 "
"#e6d67c "
"#127385 "
"#15a0dc "
"#466bff "
"#005b45 "
"#e89c62 "
"#768298 "
"#81a6bd "
"#bca599 "
"#c57c5b "
"#486b64 "
"#955553 "
"#5f3c1f "
"#b864bc "
"#f8eb9c "
"#26d6e5 "
"#5883bc "
"#67533d "
"#6e266e "
"#ff00d7 "
"#4225b8 "
"#747e44 "
"#abb136 "
"#a081d0 "
"#b000ae "
"#882a67 "
"#84816e "
"#614963 "
"#cbe5b5 "
"#7aac5d "
"#6d5877 "
"#c2b45d "
"#00bc9e "
"#72eba6 "
"#ec8c07 "
"#736646 "
"#be3bb8 "
"#8f3a58 "
"#89132d "
"#ca3801 "
"#749187 "
"#6fecd8 "
"#636474 "
"#ff4c31 "
"#701faf "
"#91adfc "
"#5eb9c2 "
"#99271d "
"#9a46db "
"#d0e6ee "
"#909a9f "
"#02f38c "
"#404fc2 "
"#a4c857 "
"#7aedff "
"#4c5250 "
"#ed7eff "
"#ffb686 "
"#8f7a4b "
"#5c4649 "
"#479273 "
"#8a86b9 "
"#7f7128 "
"#bc8dc9 "
"#447d70 "
"#4a8053 "
"#6d8ca8 "
"#b0469b "
"#afcdbd "
"#8c688c "
"#bd3438 "
"#758183 "
"#00a358 "
"#f0d7eb "
"#a485a7 "
"#635589 "
"#3e6fb3 "
"#70b8e9 "
"#e5f0b9 "
"#edfff9 "
"#99ad9a "
"#73b0af "
"#5b2f8d "
"#03622d "
"#83acdf "
"#3f5213 "
"#b65d6a "
"#dcffe1 "
"#d8b36c "
"#61d26c "
"#9e1f31 "
"#cca6ad "
"#9cbbb9 "
"#620082 "
"#7e707b "
"#a18435 "
"#c967b6 "
"#d58cff "
"#a96584 "
"#7ed2c8 "
"#8c3200 "
"#214b1d "
"#84be6e "
"#2f2e94 "
"#7acb89 "
"#4ca98b "
"#f57267 "
"#ab8ee8 "
"#ff6747 "
"#884922 "
"#d5588e "
"#a01f52 "
"#40d98a "
"#cc6f31 "
"#bfc022 "
"#454689 "
"#407922 "
"#7e8d4b "
"#a3501e "
"#e13a22 "
"#94c9e9 "
"#20019f "
"#a00e00 "
"#f3bcd2 "
"#f44a5e "
"#0965cb "
"#b4a042 "
"#77438c "
"#ac9028 "
"#cca9d0 "
"#2195b6 "
"#a9ebcb "
"#ffe3ca "
"#fff2f5 "
"#9483a8 "
"#cedcd9 "
"#876b65 "
"#c3791c "
"#76a397 "
"#a24d43 "
"#796c92 "
"#5f6833 "
"#8e82e1 "
"#99fff5 "
"#896ab1 "
"#4c933c "
"#31693c "
"#6a896e "
"#8d5c03 "
"#56af69 "
"#48829f "
"#802c3a "
"#e85f85 "
"#cd51ec "
"#9fb38c "
"#51604a "
"#b7316c "
"#00f1f3 "
"#893b37 "
"#671423 "
"#a39db5 "
"#e5e87f "
"#056e57 "
"#d6aeee "
"#9806d1 "
"#3f5a80 "
"#191bca "
"#9f9cd0 "
"#f67100 "
"#c75839 "
"#e563ba "
"#3c108e "
"#4ea9aa "
"#c1ff7f "
"#efd1d6 "
"#b09464 "
"#78564a "
"#967e93 "
"#ad79a4 "
"#b230fe "
"#734c33 "
"#b230d4 "
"#38783d "
"#f3f5ff "
"#677a6c "
"#a367fe "
"#bca3ff "
"#17ac98 "
"#ef7ea8 "
"#c34e92 "
"#69dbf3 "
"#94d69d "
"#cffff7 "
"#79ff7a "
"#9f48b5 "
"#4539c7 "
"#a8e0ff "
"#b07a8f "
"#539aa4 "
"#701bde "
"#b0a0b0 "
"#a94474 "
"#aa867f "
"#95cdd9 "
"#6b90c4 "
"#e85a00 "
"#8e7711 "
"#b6a9ac "
"#315853 "
"#fea0ff "
"#cac5e6 "
"#e7ad74 "
"#7a6469 "
"#c5d9eb "
"#5e8247 "
"#31416a "
"#86da49 "
"#849e16 "
"#a3b0d8 "
"#b6624d "
"#6b3c6a "
"#4c4aa8 "
"#637ee1 "
"#e371e6 "
"#8c308f "
"#eec76d "
"#5d5b62 "
"#a6f0ff "
"#933fbf "
"#83a48d "
"#685550 "
"#fffed3 "
"#712006 "
"#b54843 "
"#714c51 "
"#5a205b "
"#813c06 "
"#75003b "
"#8b8200 "
"#00ffe6 "
"#c88cad "
"#004975 "
"#97beff "
"#a4bbd5 "
"#ff5d93 "
"#529ce0 "
"#595c55 "
"#786f5f "
"#745524 "
"#af7679 "
"#5fea77 "
"#7e9336 "
"#a58c98 "
"#ffac40 "
"#999597 "
"#916845 "
"#6f2982 "
"#015d59 "
"#9400b5 "
"#5c3c54 "
"#a997c5 "
"#cabbc5 "
"#eecbff "
"#cb4878 "
"#842b14 "
"#9c6805 "
"#b9c0a0 "
"#d5a10a "
"#4d5a8e "
"#6b6e75 "
"#646199 "
"#e039e6 "
"#99dbdc "
"#d60986 "
"#b27b53 "
"#45c7a1 "
"#ffaf96 "
"#651e34 "
"#8d5d6b "
"#59bdb6 "
"#78c353 "
"#ae0239 "
"#6f0356 "
"#7e7d7e "
"#786900 "
"#925eea "
"#b9e540 "
"#be92b9 "
"#51543a "
"#604aab "
"#828c71 "
"#547190 "
"#c9dcca "
"#efc749 "
"#f39246 "
"#b265e5 "
"#bbb6d4 "
"#d593e8 "
"#c29742 "
"#96519d "
"#7a356a "
"#d28851 "
"#a25695 "
"#9f9947 "
"#002fff "
"#5ab423 "
"#891517 "
"#88a57a "
"#9e4487 "
"#dfd72e "
"#00e2c7 "
"#356f6e "
"#008acb "
"#725a8a "
"#7790ea "
"#d635a2 "
"#b03800 "
"#c297e7 "
"#5b5217 "
"#669772 "
"#ce6e5f "
"#f03465 "
"#ff9fdd "
"#e9001b "
"#6e5368 "
"#ab34b4 "
"#c8c4bc "
"#bdc8d3 "
"#fff440 "
"#d23640 "
"#5a6edd "
"#7b4cba "
"#b1691b "
"#78748b "
"#08847c "
"#969dae "
"#8f8d5b "
"#ca76ae "
"#6645f2 "
"#ea84e3 "
"#ad76d3 "
"#624300 "
"#5a7e27 "
"#489a8a "
"#935002 "
"#cb0056 "
"#cd515f "
"#770002 "
"#3b7a84 "
"#86458b "
"#81b9a0 "
"#f374c3 "
"#b18006 "
"#4e87d9 "
"#d0ff00 "
"#27667a "
"#ffb3e1 "
"#ffe3a9 "
"#6a3319 "
"#e1bbeb "
"#027ef7 "
"#b6c8c6 "
"#8c8a95 "
"#bfaa7b "
"#a35cb8 "
"#c7ffe5 "
"#e089c7 "
"#cae589 "
"#85b034 "
"#d7794c "
"#e7e0c9 "
"#ff42a7 "
"#254ba2 "
"#ddc8a2 "
"#e3566c "
"#358928 "
"#58766e "
"#8a96b3 "
"#ca6a87 "
"#5722a3 "
"#6177b7 "
"#99baa8 "
"#056391 "
"#fbbbb2 "
"#a77b3a "
"#640670 "
"#ba3259 "
"#917779 "
"#c42001 "
"#a09a7f "
"#92005e "
"#00f05a "
"#bdad3c "
"#9775e2 "
"#810966 "
"#d69bb6 "
"#d5cfb9 "
"#5a8e7e "
"#9a715a "
"#ea3d8f "
"#cfcb61 "
"#db693f "
"#cb9290 "
"#e18373 "
"#e2a937 "
"#81569f "
"#9e5d49 "
"#7f8430 "
"#8b8681 "
"#59483e "
"#a76cae "
"#6f7a9f "
"#379600 "
"#217b9a "
"#3d514b "
"#ff418e "
"#7e65ff "
"#d77d34 "
"#8b4f5b "
"#335036 "
"#422e96 "
"#f39296 "
"#423270 "
"#4ee7b8 "
"#44c5e7 "
"#89759e "
"#51b37f "
"#c8d89d "
"#7b34ff "
"#339554 "
"#b56f97 "
"#eeff8c "
"#416c00 "
"#d267e2 "
"#9ece00 "
"#622485 "
"#ffcaed "
"#95b1c4 "
"#ee7446 "
"#004f36 "
"#d6d6d9 "
"#8cb0b4 "
"#bb80ff "
"#665f5e "
"#00aa46 "
"#9d692a "
"#9dde66 "
"#2c32b6 "
"#ffe3ef "
"#556922 "
"#6a6e00 "
"#e0987f "
"#da6b7e "
"#e96aaa "
"#9c8e00 "
"#8930af "
"#da3cbe "
"#605677 "
"#476634 "
"#8386cc "
"#5002fe "
"#ccffa8 "
"#a7acb2 "
"#736e6d "
"#9a9ce5 "
"#a5cc76 "
"#4f5f66 "
"#845377 "
"#a36692 "
"#f5d73b "
"#637c7f "
"#500095 "
"#875843 "
"#4e495b "
"#c24823 "
"#9cf57f "
"#5dc8d5 "
"#734a00 "
"#3c4e6b "
"#e5c6de "
"#5bc487 "
"#9fed4e "
"#bfbe79 "
"#429594 "
"#b959aa "
"#e4e4f0 "
"#6e5cce "
"#3661aa "
"#b8b1ff "
"#b9cfee "
"#af2475 "
"#826e3f "
"#ec00d6 "
"#d66400 "
"#5e4f26 "
"#4c6a50 "
"#25526a "
"#730024 "
"#a23e4a "
"#ce3422 "
"#3f82b3 "
"#96f0d8 "
"#e5a6f2 "
"#bcf18c "
"#612d50 "
"#05a173 "
"#5c8d8a "
"#81644f "
"#8e7085 "
"#695c6b "
"#dc929e "
"#44515d "
"#58db27 "
"#cb8b33 "
"#a7c08c "
"#e7e1a9 "
"#ff864c "
"#d656b4 "
"#8f0001 "
"#c80ce7 "
"#b07b68 "
"#e6f2e5 "
"#ebd8d0 "
"#fd9f80 "
"#ee0249 "
"#819292 "
"#f5e1ff "
"#dab0ad "
"#d24165 "
"#743e31 "
"#926565 "
"#77add1 "
"#3aab00 "
"#678a99 "
"#e2ff46 "
"#8fba85 "
"#67e4ea "
"#005a00 "
"#8745dd "
"#91cb43 "
"#7a8892 "
"#648aff "
"#77c8a6 "
"#00c33a "
"#00978a "
"#936ba6 "
"#a99692 "
"#b5e4b3 "
"#4a4d7b "
"#e9ed64 "
"#3b8861 "
"#9b2f62 "
"#6a010c "
"#667547 "
"#58411a "
"#9772c6 "
"#5c5f3a "
"#33684c "
"#318eff "
"#4fc056 "
"#fff4da "
"#e99a35 "
"#595cbd "
"#784a1e "
"#ffc3cc "
"#b7cc15 "
"#ad2610 "
"#4fd3c5 "
"#a191b1 "
"#459fb6 "
"#4f6f7a "
"#d8512c "
"#eeb566 "
"#ffe57e "
"#b95f36 "
"#445636 "
"#7f5daf "
"#958077 "
"#add8e1 "
"#6f2d3c "
"#bd0588 "
"#bff015 "
"#9b8cc1 "
"#cdc3ff "
"#d9b453 "
"#98a195 "
"#90d482 "
"#3562e3 "
"#ecc6b8 "
"#ccdd6a "
"#0173a9 "
"#dfaf8b "
"#ea842a "
"#4a4a0f "
"#ac8fd2 "
"#5270a2 "
"#afa600 "
"#a7d0a3 "
"#aca9b9 "
"#5cb1f5 "
"#2f6262 "
"#7c5b69 "
"#7f67c1 "
"#8689a9 "
"#624730 "
"#7b6185 "
"#786232 "
"#98b2e9 "
"#578aaf "
"#be5f9c "
"#8bd5bd "
"#556cbb "
"#7c2855 "
"#e15346 "
"#f31d39 "
"#9437a4 "
"#5933de "
"#52f303 "
"#ff43cd "
"#ffd2b9 "
"#9ff7a6 "
"#e2d8eb "
"#ef4d1c "
"#9492a7 "
"#9ab934 "
"#c2339b "
"#b66a6b "
"#475e1d "
"#3a5b49 "
"#895c8d "
"#cbc9a0 "
"#7b7551 "
"#5c004a "
"#bdb392 "
"#6e7026 "
"#8e7fff "
"#337164 "
"#65727f "
"#d96eff "
"#acf3c1 "
"#00d757 "
"#84442f "
"#649bc9 "
"#9aa562 "
"#aa53e8 "
"#9b4665 "
"#6c394c "
"#d29b51 "
"#9e7401 "
"#2479d5 "
"#824678 "
"#ff92bd "
"#580001 "
"#ba99ad "
"#64cff9 "
"#30acde "
"#fffef1 "
"#a54300 "
"#d49764 "
"#bc48e6 "
"#564071 "
"#ccefed "
"#ada172 "
"#767a6f "
"#ec99b4 "
"#e4b0c0 "
"#73467a "
"#60120f "
"#378d9d "
"#d7f765 "
"#ed845e "
"#839286 "
"#4e5f77 "
"#d5614b "
"#07f8b1 "
"#50256a "
"#c3767d "
"#c78a65 "
"#f1c989 "
"#00c1b1 "
"#882142 "
"#6e8e20 "
"#bfadba "
"#738266 "
"#317e64 "
"#dc62c8 "
"#879ae3 "
"#004f54 "
"#d9b6d7 "
"#5f1900 "
"#4e50de "
"#6d9b00 "
"#cbd1ed "
"#843c4b "
"#c07bd5 "
"#cfcb8c "
"#b5854e "
"#b45acd "
"#860093 "
"#919825 "
"#267224 "
"#6e68e2 "
"#6d652a "
"#439bc4 "
"#8ec1d5 "
"#5f535d "
"#550061 "
"#754660 "
"#6e989e "
"#6f4241 "
"#eb6354 "
"#635800 "
"#7b37d0 "
"#d2bfd5 "
"#531ebd "
"#a4d5c6 "
"#00ad6e "
"#355c69 "
"#95a1ff "
"#2b5076 "
"#5a9d60 "
"#b25cff "
"#515169 "
"#7b1f29 "
"#73f64e "
"#663fc8 "
"#83e073 "
"#97004f "
"#67380e "
"#eed9ae "
"#45605f "
"#8a9fae "
"#dec2ca "
"#00efdc "
"#c0ecd7 "
"#503e7d "
"#3844fe "
"#be869b "
"#f672e5 "
"#d2af32 "
"#a06b60 "
"#bfcfab "
"#f136ff "
"#3c15a5 "
"#20800e "
"#8d4942 "
"#ffbf36 "
"#7e3718 "
"#c7337c "
"#bddefb "
"#df99e0 "
"#6b3e9d "
"#e5f8d1 "
"#9aa778 "
"#56ff92 "
"#964726 "
"#0d4bd5 "
"#696a53 "
"#8f00ee "
"#ebbf0f "
"#1c259f "
"#c2b3a4 "
"#b6a3cc "
"#89fbd0 "
"#85beb3 "
"#6f6f96 "
"#13a6ae "
"#004763 "
"#efc6a1 "
"#a85579 "
"#c19a6f "
"#89fbff "
"#d27dc3 "
"#324812 "
"#9a8e4a "
"#595c1b "
"#5c3e61 "
"#484263 "
"#9a1e6c "
"#7de1da "
"#921f04 "
"#799f5a "
"#552f62 "
"#567762 "
"#6e7c2c "
"#7d2cbd "
"#0d7246 "
"#94ad59 "
"#ff8a01 "
"#74cc38 "
"#6fad96 "
"#963236 "
"#98697e "
"#78bcdc "
"#ff49ff "
"#39bf8d "
"#0394c7 "
"#ea89b9 "
"#a77f9a "
"#3f3a7e "
"#752d2e "
"#f6a0aa "
"#24477b "
"#8274b1 "
"#f06c9a "
"#d8880e "
"#a7a786 "
"#3f8180 "
"#4e7835 "
"#04b230 "
"#c051bf "
"#6d4a8e "
"#89e1ad "
"#fe8dd5 "
"#bb74b5 "
"#a3aaf7 "
"#2296e1 "
"#817840 "
"#8a4fbd "
"#00b7d4 "
"#a27bbc "
"#3f9e36 "
"#7ca8f2 "
"#8c7565 "
"#b1445e "
"#8abaed "
"#4db154 "
"#a5896a "
"#d10070 "
"#b9de5c "
"#68195f "
"#456374 "
"#598a29 "
"#c74a4a "
"#d28584 "
"#939dc6 "
"#fb3ee2 "
"#a45b65 "
"#5c5fff "
"#8a4761 "
"#2d2284 "
"#eda5d6 "
"#c5f2fa "
"#6b2f60 "
"#ffa775 "
"#925c20 "
"#51575c "
"#366e78 "
"#a7b856 "
"#ff7584 "
"#b14b1f "
"#897c5d "
"#ab93aa "
"#7c5500 "
"#538090 "
"#64cbca "
"#a25335 "
"#296525 "
"#5e397f "
"#b2da00 "
"#b5ce88 "
"#776473 "
"#80464a "
"#e8eb3b "
"#ffc590 "
"#5c4b6c "
"#87a5ca "
"#f1b7f0 "
"#b185b6 "
"#8fa7a4 "
"#e9f19c "
"#ff596f "
"#f36128 "
"#7d53e4 "
"#7926a1 "
"#682d23 "
"#c3a5ee "
"#d273a1 "
"#95f52b "
"#bc0024 "
"#f0caf0 "
"#428873 "
"#a5ffe5 "
"#316a96 "
"#eb738c "
"#5da494 "
"#eb2000 "
"#5e865e "
"#2c5d78 "
"#a497a1 "
"#ff8597 "
"#7f1648 "
"#5e3f9d "
"#afa692 "
"#ebf8fc "
"#c4ffd3 "
"#c39f88 "
"#ca95cb "
"#8e2579 "
"#b1b400 "
"#964235 "
"#007c43 "
"#8f5ca1 "
"#0e4087 "
"#d3b281 "
"#fff2b7 "
"#8db300 "
"#844600 "
"#5c5e78 "
"#d3023c "
"#f0b598 "
"#004c25 "
"#bc477e "
"#ae422f "
"#c19e9c "
"#a75300 "
"#2ec777 "
"#af574e "
"#9c7279 "
"#729561 "
"#3982c9 "
"#cf7c6d "
"#35488d "
"#8f9673 "
"#b31465 "
"#9a9e9d "
"#b9827a "
"#39724d "
"#b0dec4 "
"#376dce "
"#7e76f9 "
"#a43421 "
"#c5cfc9 "
"#c583f2 "
"#a0cdaf "
"#5e564a "
"#a605b7 "
"#b8ca6e "
"#ffa111 "
"#2c59cb "
"#a438d5 "
"#df9f9c "
"#faffa1 "
"#3144ba "
"#e56d6c "
"#cfc7ca "
"#a9a15c "
"#4f9e7a "
"#b898d2 "
"#b5e38f "
"#ffc95b "
"#cec640 "
"#706295 "
"#6869ac "
"#b7bdae "
"#d7ba98 "
"#50b696 "
"#775abc "
"#c6f4bc "
"#ce2eff "
"#ab0013 "
"#c863f3 "
"#66efe9 "
"#bd8f24 "
"#970028 "
"#d5b81a "
"#b296ff "
"#ac3788 "
"#687faf "
"#606c69 "
"#9081c7 "
"#bbc0ff "
"#cd4d00 "
"#255e41 "
"#ff464d "
"#7871c5 "
"#b08f91 "
"#50633e "
"#d9f2ab "
"#6d397b "
"#26af5e "
"#4277e8 "
"#6cf3cf "
"#ec966e "
"#6a412c "
"#be2d47 "
"#c04334 "
"#d5bdb0 "
"#006354 "
"#a762cd "
"#94dc23 "
"#ea8585 "
"#943d6a "
"#968a93 "
"#0970c2 "
"#705e49 "
"#a6ebe4 "
"#e13335 "
"#693434 "
"#659539 "
"#c05c79 "
"#631037 "
"#6fbdd0 "
"#81a7b2 "
"#480076 "
"#8f6ad2 "
"#886377 "
"#2a5514 "
"#b8bcc9 "
"#53e691 "
"#97b96b "
"#b134a6 "
"#ced9e0 "
"#d184b5 "
"#92822b "
"#b5762f "
"#a90026 "
"#c24c67 "
"#afc5d7 "
"#c4b270 "
"#5b5b87 "
"#edf1d4 "
"#9ec8fb "
"#315052 "
"#dba279 "
"#ee67ff "
"#8772e0 "
"#667cff "
"#c35b00 "
"#a5b16e "
"#746f7c "
"#a678ff "
"#a093ef "
"#843a96 "
"#addad6 "
"#f2a04f "
"#f058af "
"#835f57 "
"#b7ba8b "
"#ba82a7 "
"#cabaea "
"#4fcf9b "
"#d0afa0 "
"#806982 "
"#493ca1 "
"#0e4e00 "
"#78bf8b "
"#d8dff8 "
"#a082e6 "
"#82949d "
"#5d666e "
"#7c2684 "
"#4da9c7 "
"#019624 "
"#948b7b "
"#5b8b41 "
"#826540 "
"#f93628 "
"#64316a "
"#6b6a83 "
"#8dd2ea "
"#6d2850 "
"#f0a2ea "
"#ee34bc "
"#bea310 "
"#acc9ce "
"#945120 "
"#76a07d "
"#4a79b2 "
"#519e00 "
"#aec03e "
"#92703c "
"#d3cce2 "
"#dac387 "
"#aba9a9 "
"#00dd3d "
"#9f9061 "
"#755a59 "
"#6cb662 "
"#b2bade "
"#b045c0 "
"#82ffa7 "
"#cda75c "
"#3aa7ec "
"#ef94ef "
"#7aca74 "
"#6f18c5 "
"#f0297e "
"#efebef "
"#933014 "
"#a9b1a7 "
"#749995 "
"#ff85a9 "
"#a3a7bf "
"#40476b "
"#d07317 "
"#446757 "
"#7f86e2 "
"#93c565 "
"#ac00dc "
"#d7db7c "
"#5edf9f "
"#675e75 "
"#415801 "
"#8d00d7 "
"#7c1e13 "
"#2b6600 "
"#a960a5 "
"#bd7058 "
"#815031 "
"#6a78cb "
"#634f98 "
"#de266c "
"#e1ca63 "
"#66a84c "
"#89e999 "
"#efa08e "
"#e37000 "
"#253e97 "
"#74505f "
"#a7c7e5 "
"#7b8414 "
"#5d008e "
"#e1e6bf "
"#c988d8 "
"#a8b9a4 "
"#008ba7 "
"#003484 "
"#de5d27 "
"#c3e0df "
"#ca00c7 "
"#2c7972 "
"#95c3c7 "
"#5f5638 "
"#807988 "
"#e6d7ff "
"#6601ea "
"#66bf39 "
"#785579 "
"#7d8da7 "
"#632da7 "
"#9e674a "
"#621d43 "
"#a12143 "
"#8b5aff "
"#627890 "
"#3d8951 "
"#fff76a "
"#bf5421 "
"#676768 "
"#cab2c9 "
"#00e3ea "
"#e3cc3f "
"#adc4ff "
"#d37f9e "
"#ee5d63 "
"#a2b5c0 "
"#ed364d "
"#b06dc3 "
"#cfe7fe "
"#3409ff "
"#efffc7 "
"#c4b93a "
"#493a68 "
"#adb7eb "
"#9b3905 "
"#70d357 "
"#7c0298 "
"#9d5684 "
"#a27a58 "
"#e38e58 "
"#ac5f75 "
"#80e4c8 "
"#345731 "
"#cccc1a "
"#9746ef "
"#f134a3 "
"#b8909d "
"#6c777c "
"#d12fde "
"#2ec1c7 "
"#826f72 "
"#d3539e "
"#d9e4d9 "
"#5356a7 "
"#f37931 "
"#49b9f0 "
"#fd005e "
"#6c502e "
"#f6816e "
"#a76f82 "
"#a1c5bb "
"#ed4d86 "
"#d5b4bc "
"#687164 "
"#8baf9b "
"#429769 "
"#b89479 "
"#bd76e5 "
"#fc6401 "
"#89a267 "
"#a1b2b4 "
"#687a76 "
"#6eaac1 "
"#7cdcb5 "
"#694360 "
"#bfc6ec "
"#7d266f "
"#60f468 "
"#002191 "
"#6c927c "
"#94855b "
"#ff6686 "
"#905572 "
"#c11a64 "
"#b9515b "
"#a86227 "
"#df4ad2 "
"#b13c45 "
"#62a873 "
"#896b24 "
"#6d49aa "
"#659aac "
"#b8bdbc "
"#94959f "
"#9a4f5a "
"#544a83 "
"#d76fba "
"#68a660 "
"#613f3a "
"#5dce7e "
"#907985 "
"#835a28 "
"#387191 "
"#c1bcbe "
"#6b92d9 "
"#d3a3c7 "
"#cb308f "
"#733605 "
"#541965 "
"#6d5b39 "
"#ba6cff "
"#70c0ff "
"#e13afe "
"#d6ddc6 "
"#f35445 "
"#556e39 "
"#bf6624 "
"#3004a0 "
"#b0e4f2 "
"#d74f51 "
"#1d8288 "
"#d80019 "
"#57635c "
"#be3f6a "
"#f3ba7e "
"#80c5d0 "
"#80848a "
"#48b640 "
"#a74e67 "
"#5a8d6c "
"#5df6ff "
"#aef968 "
"#bcb0ed "
"#008761 "
"#957393 "
"#60725a "
"#c09ec9 "
"#ade6d5 "
"#7a7c98 "
"#ecaeb3 "
"#87335d "
"#189674 "
"#462672 "
"#3db1a7 "
"#18584d "
"#b29a8a "
"#849dce "
"#6a653b "
"#6d8c4c "
"#c27446 "
"#bf798d "
"#ff6ad3 "
"#8dcecf "
"#eedc93 "
"#d4f1ff "
"#c45cd4 "
"#4e6c6e "
"#59794a "
"#ffb95a "
"#84e3ff "
"#ff9d58 "
"#4dbfa9 "
"#998145 "
"#fab0ff "
"#f2e169 "
"#dc7b8e "
"#ac2953 "
"#868a7d "
"#a16e9e "
"#ddf0ee "
"#c39d5f "
"#608299 "
"#f0c6d2 "
"#5d6656 "
"#7732e5 "
"#aba1eb "
"#76f5ba "
"#6494b6 "
"#71aa35 "
"#5c4900 "
"#cfccd5 "
"#76c4f0 "
"#eecc00 "
"#b4ae66 "
"#578281 "
"#e7b939 "
"#717b55 "
"#dee000 "
"#11da99 "
"#af608f "
"#04785a "
"#ff96ef "
"#ccef43 "
"#ff696e "
"#465222 "
"#955d8c "
"#715e00 "
"#603b4b "
"#005fff "
"#5d9098 "
"#793b58 "
"#485369 "
"#457b5b "
"#af9400 "
"#a0a341 "
"#9ab2ab "
"#7e69a0 "
"#4f5b5a "
"#95008e "
"#b6fff5 "
"#d72d7b "
"#c7e4c5 "
"#006382 "
"#800430 "
"#e0a994 "
"#5e8900 "
"#8ac602 "
"#005da7 "
"#72b600 "
"#7af8e9 "
};

#endif /* __PBARDEFS_INCLUDED__ */
