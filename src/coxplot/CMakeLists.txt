add_library(
  coxplot
  color.c
  curve.c
  find_color_name.c
  frame.c
  frstpt.c
  labmod.c
  line.c
  memplt.c
  perim.c
  periml.c
  phdot.c
  phline.c
  plot_cox.c
  plot_ps.c
  plot_ps2.c
  plotpak.inc
  point.c
  points.c
  ppak_commons.c
  ppak_perim.c
  ppak_pwrit.c
  ppak_pwritf.c
  ppak_srface.c
  pwrit.c
  pwritf.c
  set.c
  setdsh.c
  setfrm.c
  setlin.c
  setw.c
  srface.c
  tick4.c
  vector.c
  zzaxxx.c
  zzaxyy.c
  zzchar.c
  zzclip.c
  zzlabl.c
  zzlgin.c
  zzline.c
  zzlinx.c
  zzliny.c
  zzlogx.c
  zzlogy.c
  zzperi.c
  zzphph.c
  zzphys.c
)

target_include_directories(
  coxplot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE ${MOTIF_INCLUDE_DIR}
          $<TARGET_PROPERTY:AFNI::f2cdir,INTERFACE_INCLUDE_DIRECTORIES>
          
)
set_target_properties(coxplot PROPERTIES PUBLIC_HEADER "coxplot.h")
target_link_libraries(coxplot PRIVATE libheaders AFNI::f2cdir m)
add_afni_target_properties(coxplot)
add_library(AFNI::coxplot ALIAS coxplot)
