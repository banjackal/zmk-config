/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>

#define DVORAK 0
#define NUMBERS 1
#define SYMBOLS 2
#define FUNCTION 3

&lt {
        retro-tap;
};
&kscan0 {
    debounce-period = <10>;
};

/ {
        behaviors {
                hm: homerow_mods {
                compatible = "zmk,behavior-hold-tap";
                label = "HOMEROW_MODS";
                #binding-cells = <2>;
                tapping-term-ms = <175>;
                flavor = "tap-preferred";
                bindings = <&kp>, <&kp>;
                };
        };

//-------------------------------------------------------------
// 3x5 key indices for combo mapping
// |  1 |  2 |  3 |  4 |  5 |        |  6 |  7 |  8 |  9 | 10 | 
// | 13 | 14 | 15 | 16 | 17 |        | 18 | 19 | 20 | 21 | 22 |
// | 25 | 26 | 27 | 28 | 29 |        | 30 | 31 | 32 | 33 | 34 | 
//              | 36 | 37 | 38 |   | 39 | 40 | 41 |
//------------------------------------------------------------- 

        combos {
                compatible = "zmk,combos";
                combo_esc {
                        timeout-ms = <50>;
                        key-positions = <13 14>;
                        bindings = <&kp ESC>;
                };
                combo_ins {
                        timeout-ms = <50>;
                        key-positions = <7 8>;
                        bindings = <&kp INS>;                
                };
                combo_del {
                        timeout-ms = <50>;
                        key-positions = <9 10>;
                        bindings = <&kp DEL>;                
                };
                combo_caps {
                        timeout-ms = <50>;
                        key-positions = <25 34>;
                        bindings = <&kp CAPS>;
                        layers = <0>;
                };
                combo_enter {
                        timeout-ms = <50>;
                        key-positions = <21 22>;
                        bindings = <&kp RET>;
                        layers = <0>;
                };
                combo_tab {
                        timeout-ms = <50>;
                        key-positions = <1 2>;
                        bindings = <&kp TAB>;
                        layers = <0>;
                };
                combo_rctrl {
                        timeout-ms = <50>;
                        key-positions = <26 33>;
                        bindings = <&kp RCTRL>;
                        layers = <0>;
                };
                combo_ralt {
                        timeout-ms = <50>;
                        key-positions = <27 32>;
                        bindings = <&kp RALT>;
                        layers = <0>;
                };
        };

        keymap {
                compatible = "zmk,keymap";

                dvorak_layer {
                        bindings = <
   &none &kp Q &kp W &kp F &kp P &kp B                          &kp J &kp L &kp U &kp Y &kp SEMI &none
   &none &kp A &kp R &kp S &kp T &kp G                          &kp M &kp N &kp E &kp I &kp O &none
   &none &hm LSHFT Z &hm LCTRL X &hm LALT C &hm LGUI D &kp V    &kp K &hm LGUI H &hm LALT COMMA &hm LCTRL DOT &hm LSHFT SQT &none
                  &none &none &none                             &lt NUMBERS BSPC &lt SYMBOLS SPACE &lt FUNCTION none
                        >;
                };

                numbers_layer {
                        bindings = <
   &none &kp N1   &kp N2   &kp N3    &kp N4    &kp N5     &kp N6   &kp N7    &kp N8    &kp N9    &kp N0 &none
   &none &none    &none &none &none &none                    &kp LEFT &kp DOWN  &kp UP    &kp RIGHT &none  &none
   &none &none    &none &none     &none     &none      &kp HOME &kp PG_DN &kp PG_UP &kp END   &none  &none
                         &none     &none       &none        &trans &none &none
                        >;
                };

                symbols_layer {
                        bindings = <
   &none &kp EXCL  &kp AT    &kp LT   &kp GT   &none     &none     &kp LBKT &kp RBKT  &kp UNDER &kp SLASH  &none
   &none &kp BSLH  &kp POUND &kp LPAR &kp RPAR &kp PIPE  &kp PRCNT &kp LBRC &kp RBRC  &kp EQUAL &kp MINUS  &none
   &none &kp QMARK &kp GRAVE &kp STAR &kp PLUS &none     &none     &kp AMPS &kp CARET &kp TILDE &kp DOLLAR &none
                        &none &none &none  &none &trans &none
                        >;
                };

                function_layer {
                        bindings = <
   &none &kp F1   &kp F2   &kp F3    &kp F4    &kp F5  &kp F6  &kp F7    &kp F8    &kp F9   &kp F10  &none
   &none &none &none &none &none     &kp F11   &kp F12 &none   &none     &none     &none &kp PSCRN
   &none &bt BT_CLR    &none &bt BT_PRV     &bt BT_NXT      &none   &none   &none     &none     &out OUT_BLE &out OUT_USB    &none
                        &none &none &none &none &none &trans
                        >;
                };
        };
};
