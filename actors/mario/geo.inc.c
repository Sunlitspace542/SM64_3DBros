// Normal Mario Geo

extern Gfx mario_cap_on_eyes_front[];
extern Gfx mario_cap_on_eyes_half_closed[];
extern Gfx mario_cap_on_eyes_closed[];
extern Gfx mario_cap_on_eyes_right[];
extern Gfx mario_cap_on_eyes_left[];
extern Gfx mario_cap_on_eyes_up[];
extern Gfx mario_cap_on_eyes_down[];
extern Gfx mario_cap_on_eyes_dead[];

// 0x170002E0
const GeoLayout mario_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x1700041C
const GeoLayout mario_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000494
const GeoLayout mario_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// The body loads all the parts with some shared dls to apply the solid color of the dl that has it, the same rule applies to the medium and low poly geos

// 0x1700053C
const GeoLayout mario_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x170006F8
const GeoLayout mario_geo_medium_poly_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000770
const GeoLayout mario_geo_medium_poly_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000818
const GeoLayout mario_geo_medium_poly_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x170009D4
const GeoLayout mario_geo_low_poly_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000B10
const GeoLayout mario_geo_low_poly_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000B88
const GeoLayout mario_geo_low_poly_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000C30
const GeoLayout mario_geo_low_poly_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Vanish Mario Geo

// 0x17000DEC
const GeoLayout mario_vanish_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000F28
const GeoLayout mario_vanish_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000FA0
const GeoLayout mario_vanish_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Same rule body as Normal Mario

// 0x17001048
const GeoLayout mario_vanish_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001204
const GeoLayout mario_vanish_geo_medium_poly_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x1700127C
const GeoLayout mario_vanish_geo_medium_poly_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001324
const GeoLayout mario_vanish_geo_medium_poly_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x170014E0
const GeoLayout mario_vanish_geo_low_poly_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x1700161C
const GeoLayout mario_vanish_geo_low_poly_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001694
const GeoLayout mario_vanish_geo_low_poly_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x1700173C
const GeoLayout mario_vanish_geo_low_poly_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Metal Mario Geo

// 0x170018F8
const GeoLayout mario_metal_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x170019A4
const GeoLayout mario_metal_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001A1C
const GeoLayout mario_metal_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// A difference from Normal Mario is that the dls after the butt and left thigh shares the metal texture of it, same rule applies to the medium and low poly geos

// 0x17001AC4
const GeoLayout mario_metal_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001C80
const GeoLayout mario_metal_geo_medium_poly_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001CF8
const GeoLayout mario_metal_geo_medium_poly_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001DA0
const GeoLayout mario_metal_geo_medium_poly_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001F5C
const GeoLayout mario_metal_geo_low_poly_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002008
const GeoLayout mario_metal_geo_low_poly_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002080
const GeoLayout mario_metal_geo_low_poly_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002128
const GeoLayout mario_metal_geo_low_poly_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Metal Vanish Mario Geo

// 0x170022E4
const GeoLayout mario_metal_vanish_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002390
const GeoLayout mario_metal_vanish_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002408
const GeoLayout mario_metal_vanish_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Same rules as Metal Mario

// 0x170024B0
const GeoLayout mario_metal_vanish_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x1700266C
const GeoLayout mario_metal_vanish_geo_medium_poly_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x170026E4
const GeoLayout mario_metal_vanish_geo_medium_poly_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x1700278C
const GeoLayout mario_metal_vanish_geo_medium_poly_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002958
const GeoLayout mario_metal_vanish_geo_low_poly_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002A04
const GeoLayout mario_metal_vanish_geo_low_poly_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002A7C
const GeoLayout mario_metal_vanish_geo_low_poly_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_closed),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_closed),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002B24
const GeoLayout mario_metal_vanish_geo_low_poly_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 63, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 60, -10, -63, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 39, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// High Poly

// 0x17002CE0
const GeoLayout mario_geo_load_body[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_cap_effect),
   GEO_OPEN_NODE(),
      GEO_BRANCH(1, mario_geo_body),
      GEO_BRANCH(1, mario_vanish_geo_body),
      GEO_BRANCH(1, mario_metal_geo_body),
      GEO_BRANCH(1, mario_metal_vanish_geo_body),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Medium Poly

// 0x17002D14
const GeoLayout mario_geo_load_medium_poly_body[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_cap_effect),
   GEO_OPEN_NODE(),
      GEO_BRANCH(1, mario_geo_medium_poly_body),
      GEO_BRANCH(1, mario_vanish_geo_medium_poly_body),
      GEO_BRANCH(1, mario_metal_geo_medium_poly_body),
      GEO_BRANCH(1, mario_metal_vanish_geo_medium_poly_body),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Low Poly

// 0x17002D48
const GeoLayout mario_geo_load_low_poly_body[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_cap_effect),
   GEO_OPEN_NODE(),
      GEO_BRANCH(1, mario_geo_low_poly_body),
      GEO_BRANCH(1, mario_vanish_geo_low_poly_body),
      GEO_BRANCH(1, mario_metal_geo_low_poly_body),
      GEO_BRANCH(1, mario_metal_vanish_geo_low_poly_body),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002D7C
const GeoLayout mario_geo_render_body[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_RENDER_RANGE(-2048, 600),
      GEO_OPEN_NODE(),
         GEO_BRANCH(1, mario_geo_load_body),
      GEO_CLOSE_NODE(),
      GEO_RENDER_RANGE(600, 1600),
      GEO_OPEN_NODE(),
         GEO_BRANCH(1, mario_geo_load_medium_poly_body),
      GEO_CLOSE_NODE(),
      GEO_RENDER_RANGE(1600, 32767),
      GEO_OPEN_NODE(),
         GEO_BRANCH(1, mario_geo_load_low_poly_body),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// This last geo is used to load all of Mario Geo in the Level Scripts

// 0x17002DD4
const GeoLayout mario_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_PLAYER, 0xB4, 100),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 16384),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mirror_mario_backface_culling),
         GEO_ASM(0, geo_mirror_mario_set_alpha),
         GEO_SWITCH_CASE(0, geo_switch_mario_stand_run),
         GEO_OPEN_NODE(),
            GEO_BRANCH(1, mario_geo_load_body),
            GEO_BRANCH(1, mario_geo_render_body),
         GEO_CLOSE_NODE(),
         GEO_ASM(1, geo_mirror_mario_backface_culling),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
