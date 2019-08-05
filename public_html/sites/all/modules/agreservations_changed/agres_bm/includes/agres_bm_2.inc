<?php

/**
 * @file
 * agres_bm -> bookingmode base class to derive from when creating new
 * bookingmodes
 */
require_once('./' . drupal_get_path('module', 'agres_bm') . '/includes/agres_bm.inc');

/**
 * 
 */
class agres_bm_2 extends agres_bm {

    //display booking and reservation info in the ubercart cart
    static function agr_cart_info_form() {
        
    }

    //_searchwidget_form
    static function _agr_searchwidget_form($form_state, $args) {
//       

        $cat = $args['build_info']['args'][0];
//    drupal_set_message('<pre>_agr_searchwidget_form_agr_searchwidget_formcategorie::::'.print_r($cat,true).'</pre>');
        $lang = 'und';
        $lang = field_language('node', $cat, 'field_agres_datelabel1');
        $datform_default = date_default_format('date_popup');
        $datform = str_replace(':s', '', $datform_default);
        $datform = 'Y-m-d';
//  $datform = str_replace('H:i','', $datform);
//  $datform = str_replace('H:i:s','', $datform);
//  $datform .= ' H:i';
        $langbm = 'und';
        $langbm = field_language('node', $cat, 'field_agres_bookingmode');

        $currentpath = current_path(); //widgetagrviewsearch;
        if ($currentpath == 'agrembed/widgetview') {
            $form['#attributes']['target'] = '_blank';
//       drupal_set_message('<pre>_agr_searchwidget_form_agr_searchwidget_formcategorie::::'.print_r(current_path(),true).'</pre>');
        }

        $form['unitsearch']['checkin' . $cat->nid] = array(
            '#type' => 'date_popup',
            '#title' => $cat->field_agres_datelabel1[$lang][0]['safe_value'],
            '#required' => TRUE,
            '#size' => 13,
            '#date_type' => 'datetime',
            '#date_timezone' => date_default_timezone(), //Y-m-d H:i
            '#date_format' => $datform,
            '#default_value' => '',
            '#date_year_range' => '-0:+1',
//  '#suffix' => '</div>',
            '#weight' => 100,
        );


        $timeoptions = _agres_categories_create_options_servicehours(0, $cat);
        $lang = 'und';
        $lang = field_language('node', $cat, 'field_agres_showtime');
        if (($cat->field_agres_showtime[$lang][0]['value'] == 1) || ($cat->field_agres_showtime[$lang][0]['value'] == 2)) {

//      drupal_set_message('<pre>categorie::::'.print_r($cat->nid,true).'</pre>');
            $form['unitsearch']['checkin' . $cat->nid]['checkintime'] = array(
//      '#prefix' => '<div>',
                '#type' => 'select',
                '#title' => 'time', //$category->title . ' ' . t('count'), //t('Units'),
                '#default_value' => reset($timeoptions),
                '#options' => $timeoptions,
//      '#suffix' => '</div>',
                '#weight' => 150,
            );
//    $datform .= ' H:i';
        }
        $lang = 'und';
        $lang = field_language('node', $cat, 'field_agres_datelabel2');

        $timeoptions1 = _agres_categories_create_options_servicehours(0, $cat);
        $lang = 'und';
        $lang = field_language('node', $cat, 'field_agres_showtime');
        if (isset($cat->field_agres_datelabel2[$lang][0]['safe_value'])) {
            $form['unitsearch']['checkout' . $cat->nid] = array(
//      '#prefix' => '<div>',
                '#type' => 'date_popup',
                '#title' => $cat->field_agres_datelabel2[$lang][0]['safe_value'],
                //      '#default_value' =>
                '#required' => TRUE,
                '#size' => 13,
                '#date_type' => 'datetime',
                '#date_timezone' => date_default_timezone(),
                '#date_format' => $datform,
                '#default_value' => '',
                '#date_year_range' => '-0:+1',
//      '#suffix' => '</div>',
                '#weight' => 200,
            );
            if ($cat->field_agres_showtime[$lang][0]['value'] > 0) {
                //
                $form['unitsearch']['checkout' . $cat->nid]['checkouttime'] = array(
                    //      '#prefix' => '<div>',
                    '#type' => 'select',
                    '#title' => 'time', //$category->title . ' ' . t('count'), //t('Units'),
                    '#default_value' => reset($timeoptions1),
                    '#options' => $timeoptions1,
                    //      '#suffix' => '</div>',
                    '#weight' => 250,
                );
                $datform .= ' H:i';
            }
        } elseif (($cat->field_agres_showtime[$lang][0]['value'] == 3) || ($cat->field_agres_showtime[$lang][0]['value'] == 1)) {
            $form['unitsearch']['checkin' . $cat->nid]['checkouttime'] = array(
                //      '#prefix' => '<div>',
                '#type' => 'select',
                '#title' => 'time', //$category->title . ' ' . t('count'), //t('Units'),
                '#default_value' => reset($timeoptions1),
                '#options' => $timeoptions1,
                //      '#suffix' => '</div>',
                '#weight' => 200,
            );
            $datform .= ' H:i';
        }


        $langnu = 'und';
        $langnu = field_language('node', $cat, 'field_agres_shownumberunits');
        if ($cat->field_agres_shownumberunits[$lang][0]['value'] == 1) {
            $lang = 'und';
            $lang = field_language('node', $cat, 'field_agres_unitslabel');
            if (isset($cat->field_agres_unitslabel[$lang])) {
                $title = $cat->field_agres_unitslabel[$lang][0]['safe_value'];
            } else {
                $title = t('units');
            }
            $lang = 'und';
            $lang = field_language('node', $cat, 'field_agres_numberunits');

            $form['unitsearch']['units'] = array(
//      '#prefix' => '<div>',
                '#type' => 'select',
                '#title' => $title, //$category->title . ' ' . t('count'), //t('Units'),
                '#default_value' => $cat->field_agres_numberunits[$langnu][0]['value'],
                '#options' => array(
                    1 => 1,
                    2 => 2,
                    3 => 3,
                    4 => 4,
                    5 => 5,
                    6 => 6,
                    7 => 7,
                    8 => 8,
                    9 => 9,
                    10 => 10,
                ),
//      '#suffix' => '</div>',
                '#weight' => 300,
            );
        }

        $form['unitsearch']['submit'] = array(
//    '#prefix' => '<div>',
            '#type' => 'submit',
            '#title' => 'Search',
            '#value' => t('Calculate Price'),
            // '#submit' => array('agres_categories_searchwidget_form_submit'),
//    '#suffix' => '</div>',
            '#weight' => 500,
        );

        return $form;
    }

    //_searchwidget_form_validate
    static function _agr_searchwidget_form_validate($form, &$form_state) {
        if (module_exists('uc_cart')) {
            $items = uc_cart_get_contents(uc_cart_get_id());
            // Now delete the reservations. In case where not allowed to delete,
            // follow the suggestion posted here:http://drupal.org/node/218104
            foreach ($items as $productunit) {
                if (isset($productunit->data['agreservations_resid'])) {
                    if (intval($productunit->data['agreservations_resid']) > 0) {
                        global $user;
                        $original_user = $user;
                        drupal_save_session(FALSE);
                        $user = user_load(1);
                        node_delete(intval($productunit->data['agreservations_resid']));
                        // Restore original user
                        $user = $original_user;
                        drupal_save_session(TRUE);
                    }
                }
            }
            uc_cart_empty(uc_cart_get_id());
            if (isset($_SESSION['availableunittypes'])) {
                unset($_SESSION['availableunittypes']);
            }
            if (isset($_SESSION['agreservationuserrequest'])) {
                unset($_SESSION['agreservationuserrequest']);
            }
        }
//  drupal_set_message('<pre>agres_categories_searchwidget_form_validate::::'.print_r($form_state,true).'</pre>');
        $datform = 'Y-m-d H:i:s'; //:s
        if (isset($form_state['build_info']['args'][0])) {
            $cat = $form_state['build_info']['args'][0];
            $lang = 'und';
            $lang = field_language('node', $cat, 'field_agres_showtime');
            $langd = 'und';
            $langd = field_language('node', $cat, 'field_agres_datelabel1');


            if (!isset($form_state['values']['units'])) {

                $form_state['values']['units'] = 1;
            }
            $requestedunits = 1;
            $requestedunits = $form_state['values']['units'];

            if (!isset($form_state['input']['checkin' . $cat->nid]['date'])) {
                form_set_error('unitinfo', t('First Date has to be entered.'));
                return;
            }
            if (!isset($form_state['input']['checkin' . $cat->nid]['checkintime']) && ($cat->field_agres_showtime[$lang][0]['value'] == 1)) {
                form_set_error('unitinfo', t('Time for first Date has to be entered.'));
                return;
            }
            $form_state['values']['checkin' . $cat->nid] = $form_state['input']['checkin' . $cat->nid]['date'];
//    drupal_set_message('<pre>agres_categories_searchwidget_form_validate'.print_r($form_state['input']['checkin'.$cat->nid]['checkintime'],true).'</pre>');
            if (isset($form_state['input']['checkin' . $cat->nid]['checkintime'])) {
                $form_state['values']['checkin' . $cat->nid] .=' ' . $form_state['input']['checkin' . $cat->nid]['checkintime'];
            }
            $tmpDateCheckin = date_create($form_state['values']['checkin' . $cat->nid]);

            if (!isset($form_state['input']['checkout' . $cat->nid]['date'])) {
                if (isset($cat->field_agres_datelabel2[$lang][0]['safe_value'])) {
                    form_set_error('unitinfo', t('Second Date has to be entered.'));
                    return;
                } else {
                    if (!isset($form_state['input']['checkin' . $cat->nid]['date'])) {
                        form_set_error('unitinfo', t('Date has to be entered.'));
                        return;
                    } else {
                        $form_state['input']['checkout' . $cat->nid]['date'] = $form_state['input']['checkin' . $cat->nid]['date'];
                        if (isset($form_state['input']['checkin' . $cat->nid]['checkouttime'])) {
                            $form_state['input']['checkout' . $cat->nid]['checkouttime'] = $form_state['input']['checkin' . $cat->nid]['checkouttime'];
                        } elseif (isset($form_state['input']['duration' . $cat->nid])) {
                            $tmpDateCheckout = date_create($form_state['values']['checkin' . $cat->nid]);
                            $tmpDateCheckout->modify('+' . $form_state['input']['duration' . $cat->nid]);
                            $form_state['input']['checkout' . $cat->nid]['date'] = $tmpDateCheckout->format('Y-m-d');
                            $form_state['input']['checkout' . $cat->nid]['checkouttime'] = $tmpDateCheckout->format('H:i');
//                         drupal_set_message('<pre>___###'.print_r($tmpDateCheckout->format('H:i'),true).'</pre>');
//                        $form_state['input']['checkout' . $cat->nid]['checkouttime'] = $form_state['input']['checkin' . $cat->nid]['checkouttime'];
                        }
                    }
                }

//      drupal_set_message('<pre>zeittttt_ '.print_r($form_state['input'],true).'</pre>');
            }
            if (!isset($form_state['input']['checkout' . $cat->nid]['checkouttime']) && ($cat->field_agres_showtime[$lang][0]['value'] == 1)) {
                form_set_error('unitinfo', t('Time for second Date has to be entered.'));
                return;
            }
            $form_state['values']['checkout' . $cat->nid] = $form_state['input']['checkout' . $cat->nid]['date'];
            if ((isset($form_state['input']['checkin' . $cat->nid]['checkintime'])) && (isset($form_state['input']['checkout' . $cat->nid]['checkouttime']))) {
                $form_state['values']['checkout' . $cat->nid] .= ' ' . $form_state['input']['checkout' . $cat->nid]['checkouttime'];
            }
            $tmpDateCheckout = date_create($form_state['values']['checkout' . $cat->nid]);
            //days a reservation has to be in the future:
            $langdia = 'und';
            $langdia = field_language('node', $cat, 'field_agres_mindaysadvance');
            if (isset($cat->field_agres_mindaysadvance[$lang])) {
                $mindaysinadvance = $cat->field_agres_mindaysadvance[$lang][0]['value'];
                $tmptodayplus = date_create();
                date_modify($tmptodayplus, '+' . $mindaysinadvance . ' days');
                if (!is_a($tmpDateCheckin, 'DateTime')) {
//         drupal_set_message('<pre> allet nict juut '.print_r($mindaysinadvance,true).'</pre>');
                    form_set_error('unitinfo', t('Please enter valid dates only!') . $mindaysinadvance . t(' days in advance'));
                } else {
//         drupal_set_message('<pre> allet juut '.print_r($mindaysinadvance,true).'</pre>');
                    if ($tmptodayplus->format('Y-m-d') > $tmpDateCheckin->format('Y-m-d')) {
                        form_set_error('unitinfo', t('Checkin-time has to be at least ') . $mindaysinadvance . t(' days in advance'));
                    }
                }
            }

            $langsnu = 'und';
            $langsnu = field_language('node', $cat, 'field_agres_shownumberunits');
            $langnu = 'und';
            $langnu = field_language('node', $cat, 'field_agres_numberunits');
            if (($cat->field_agres_shownumberunits[$langsnu][0]['value'] !== '1') && (isset($cat->field_agres_numberunits[$langnu][0]['value']))) {
//      drupal_set_message('<pre>agresdddddddddd_categories_searchwidget_form_validate'.print_r($cat->field_agres_shownumberunits[$langsnu][0]['value'],true).'</pre>');
                $form_state['values']['units'] = $cat->field_agres_numberunits[$langnu][0]['value'];
            }

            if (!is_a($tmpDateCheckout, 'DateTime')) {
                form_set_error('unitinfo', t('Please enter valid dates only!') . $mindaysinadvance . t(' days in advance'));
            } else {
                //check restrictions if modules is enabled:
                if (module_exists('agres_restriction') && (variable_get('agr_checkglobalrestriction_swidget', 'yes') == 'yes')) {
                    $message = agres_timeframe_api('check_restrictions', array(
                        'start_date' => $form_state['values']['checkin' . $cat->nid],
                        'end_date' => $form_state['values']['checkout' . $cat->nid],
                    ));
                }
                $langdcit = 'und';
                $langdcit = field_language('node', $cat, 'field_agres_defaultcheckintime');
                $langdcot = 'und';
                $langdcot = field_language('node', $cat, 'field_agres_defaultcheckouttime');
                $langst = 'und';
                $langst = field_language('node', $cat, 'field_agres_showtime');
                if (($cat->field_agres_showtime[$langst][0]['value'] <> 1) && (isset($cat->field_agres_defaultcheckintime[$langdcit][0]['value']))) {
                    date_modify($tmpDateCheckin, $cat->field_agres_defaultcheckintime[$langdcit][0]['value']);
                    $form_state['values']['checkin' . $cat->nid] = $tmpDateCheckin->format($datform);
                    date_modify($tmpDateCheckout, $cat->field_agres_defaultcheckouttime[$langdcot][0]['value']);
                    $form_state['values']['checkout' . $cat->nid] = $tmpDateCheckout->format($datform);
                }

                /*                 * *******************check servicehours!****************************************************************** */

                $checkinisinrange = _agres_categories_check_servicehours($tmpDateCheckin, $cat);
                $checkoutisinrange = _agres_categories_check_servicehours($tmpDateCheckout, $cat);
                if ($checkinisinrange === FALSE) {
                    form_set_error('unitinfo', t('Checkin-time has to be within service hours '));
                }
                if ($checkoutisinrange === FALSE) {
                    form_set_error('unitinfo', t('Checkout-time has to be within service hours '));
                }

                $langbm = 'und';
                $langbm = field_language('node', $cat, 'field_agres_bookingmode');

                if ($tmpDateCheckin >= $tmpDateCheckout) {
                    form_set_error('unitinfo', t('Checkin has to be before Checkout '));
                }


                if ($tmpDateCheckin <= new DateTime()) {
                    form_set_error('unitinfo', t('Checkin is has to be in the future !!! '));
                }
//    $checkintime = date_format($tmpDateCheckin, 'Y-m-d H:i:s');
//    $checkouttime = date_format($tmpDateCheckout, 'Y-m-d H:i:s');
                /* get reservable units: */
                $resnodes = agreservations_get_reservable_items('agreservations_unit', date_format($tmpDateCheckin, 'Y-m-d H:i'), date_format($tmpDateCheckout, 'Y-m-d H:i'), $cat);
                $foundunits = count($resnodes);
                if ($requestedunits > 0) {
                    if ($requestedunits > $foundunits) {
                        form_set_error('unitinfo', t('Not enough free units found.'));
                    }
                } elseif ($requestedunits == 0) {
                    $langsnu = 'und';
                    $langsnu = field_language('node', $cat, 'field_agres_shownumberunits');
                    $langsm = 'und';
                    $langsm = field_language('node', $cat, 'field_agres_unitselectionmethod');
                    if (!($cat->field_agres_shownumberunits[$langsnu][0]['value'] == 2 && $cat->field_agres_unitselectionmethod[$langsm][0]['value'] == 2)) {
                        form_set_error('unitinfo', t('Number of units has to be > 0'));
                    }
                }
//    $tmpagres_onlineformjelements = variable_get('agres_onlineformjelements', 'standard');
            }
        } else {
            form_set_error('unitinfo', t('agres_category not set! Please try again'));
        }
    }

    //_searchwidget_form_submit
    static function _agr_searchwidget_form_submit($form, &$form_state) {

        if (isset($form_state['build_info']['args'][0])) {
            $cat = $form_state['build_info']['args'][0];
            $lang = 'und';
            $lang = field_language('node', $cat, 'field_agres_showtime');


            $preselectedunit = 0;
            if (isset($_SESSION['agres_current_page_nid'])) {
                $currently_viewed_producttype = null;
                $currently_viewed_producttype = node_load($_SESSION['agres_current_page_nid']);
                if (_agres_categories_unittype_has_cat($_SESSION['agres_current_page_nid'], $cat->nid)) {
                    $preselectedunit = $_SESSION['agres_current_page_nid'];
                }
            }
            if (isset($form_state['build_info']['args'][0])) {
                if (isset($form_state['values']['adults'])) {
                    $adults = $form_state['values']['adults'];
                }

                if (isset($form_state['values']['children'])) {
                    $children = $form_state['values']['children'];
                }

                if (isset($form_state['values']['units'])) {
                    $requestedunits = $form_state['values']['units'];
                }
                if (isset($form_state['values']['checkin' . $cat->nid])) {
                    $tmpDateCheckin = date_create($form_state['values']['checkin' . $cat->nid]);
                }

                if (isset($form_state['values']['checkout' . $cat->nid])) {
                    $tmpDateCheckout = date_create($form_state['values']['checkout' . $cat->nid]);
                }
                $checkintime = date_format($tmpDateCheckin, 'Y-m-d H:i:s');
                $checkouttime = date_format($tmpDateCheckout, 'Y-m-d H:i:s');

                $langbm = 'und';
                $langbm = field_language('node', $cat, 'field_agres_bookingmode');

                if (intval($cat->field_agres_bookingmode[$langbm][0]['value']) == 2) {
                    if (isset($form_state['build_info']['args'][0])) {
                        $categorynid = $form_state['build_info']['args'][0]->nid;
                        $resnodes = agreservations_get_reservable_items('agreservations_unit', date_format($tmpDateCheckin, 'Y-m-d H:i:s'), date_format($tmpDateCheckout, 'Y-m-d H:i:s'), $categorynid);
                    } else {
                        
                    }
                    $availableunittypes = _agreservations_get_reservable_unittypes($resnodes, FALSE);
                    $_SESSION['availableunittypes'] = $availableunittypes;

                    $userrequest['checkintime'] = $checkintime;
                    $userrequest['checkouttime'] = $checkouttime;
                    if (isset($adults)) {
                        $userrequest['adults'] = $adults;
                    }
                    if (isset($children)) {
                        $userrequest['children'] = $children;
                    }

                    if (isset($requestedunits)) {
                        $userrequest['requestedunits'] = $requestedunits;
                    } else {
                        $userrequest['requestedunits'] = 1;
                        $requestedunits = 1;
                    }
                    $datstr = date_format($tmpDateCheckin, 'YmdHis') . date_format($tmpDateCheckout, 'YmdHis') . $requestedunits;
                    $cat = $form_state['build_info']['args'][0];
                    $form_state['rebuild'] = true;
                    unset($form_state['values']);

                    $availableunittypenids = array_keys($availableunittypes);
                    if (in_array($preselectedunit, $availableunittypenids)) {
                        $userrequest['preselectedunit'] = $preselectedunit;
                        $_SESSION['agreservationuserrequest'] = $userrequest;
                        $_SESSION['agreservationcategory'] = $cat->nid;
                        _agres_bookings_reserve_and_fillcart(null, null, $userrequest, $cat->nid, $preselectedunit, array(), 'cart', $form_state);
                    } else {

                        $agrsearchredirect = agres_categories_search_result($userrequest, $cat, $datstr);
                    }
                }
                drupal_goto($agrsearchredirect);
            } else {
                $content = '<div>' . t('Category not set') . '</div>';
                $content = $content . '<br><a href="' . base_path() . '">' . t('back') . '<a>';
                print theme('page', $content);
            }
        } else {
            drupal_set_message('Category not set!');
        }
    }

    //call this inside hook_form
    static function _agr_get_details_form() {
        $userrequest = $_SESSION['agreservationuserrequest'];
        $flightnumber = '';
        $pickupplate = '';
        $referencenumber = '';
        $numberpersons = '1';
        $firstname = '';
        $lastname = '';
        $email = '';
        if (isset($_SESSION['agreservationuserrequest']['numberpassengers'])) {
            $numberpersons = $_SESSION['agreservationuserrequest']['numberpassengers'];
        }
        if (isset($_SESSION['agreservationuserrequest']['firstname'])) {
            $firstname = $_SESSION['agreservationuserrequest']['firstname'];
        }
        if (isset($_SESSION['agreservationuserrequest']['lastname'])) {
            $lastname = $_SESSION['agreservationuserrequest']['lastname'];
        }
        if (isset($_SESSION['agreservationuserrequest']['email'])) {
            $email = $_SESSION['agreservationuserrequest']['email'];
        }
        $form = array();
        $fieldsetclass = 'agr_additionalinfo_';
        if (isset($_SESSION['agreservationuserrequest']['pickuppoint'])) {
            $fieldsetclass .= $_SESSION['agreservationuserrequest']['pickuppoint'];
        }
        $fieldsetclassdest = 'agr_additionalinfo_dest_';
        if (isset($_SESSION['agreservationuserrequest']['dropoffpoint'])) {
            $fieldsetclassdest .= $_SESSION['agreservationuserrequest']['dropoffpoint'];
        }
        $form['agrdetails'] = array(
            '#prefix' => '<div class="' . $fieldsetclass . ' ' . $fieldsetclassdest . '">',
            '#type' => 'fieldset',
//  '#title' => t('Additional Info'),
            '#weight' => 5,
            '#collapsible' => FALSE,
            '#collapsed' => FALSE,
            '#suffix' => '</div>',
        );
        $form['agrdetails']['numberpersons'] = array(
            '#required' => '1',
            '#multiple' => '0',
            '#key_type_toggled' => '0',
            '#default_value' => $numberpersons,
            '#weight' => '3',
            '#type' => 'select',
            '#options' => array(
                '1' => t('1'),
                '2' => t('2'),
                '3' => t('3'),
                '4' => t('4'),
                '5' => t('5'),
                '6' => t('6'),
                '7' => t('7'),
                '8' => t('8'),
                '9' => t('9'),
            ),
            '#multiple_toggle' => '1',
            '#title' => t('Enter Number of Passengers'),
        );

        $form['agrdetails']['firstname'] = array(
            '#required' => '0',
            '#description' => t('First name'),
            '#weight' => '5',
            '#type' => 'textfield',
            '#default_value' => $firstname,
            '#title' => t('First name'),
        );

        $form['agrdetails']['lastname'] = array(
            '#required' => '0',
            '#description' => t('last name'),
            '#weight' => '6',
            '#type' => 'textfield',
            '#default_value' => $lastname,
            '#title' => t('last name'),
        );

        $form['agrdetails']['email'] = array(
            '#required' => '0',
            '#description' => t('Contact E-Mail'),
            '#weight' => '7',
            '#type' => 'textfield',
            '#default_value' => $email,
            '#title' => t('Contact E-Mail'),
        );

//  $form['#validate']
        $form['submit'] = array(
            '#type' => 'submit',
            '#value' => t('Continue'),
            '#id' => 'submit-unitselect',
            '#submit' => array('agres_categories_get_details_submithandler'),
//      '#validate' =>array('agres_bm_3::_agr_get_details_form_validate'),
            '#attributes' => array(
                'class' => array('submit-additional-info'),
            ),
            '#weight' => '5',
        );

        return $form;
    }

    //call this inside hook_form_validate
    static function _agr_get_details_form_validate($form, &$form_state) {
        //Basic validation first:  
        if (($form_state['values']['firstname'] == '' || $form_state['values']['firstname'] === null)) {
            drupal_set_message(t('Please enter your first name.'), 'error');
            return;
        }
        if (($form_state['values']['lastname'] == '' || $form_state['values']['lastname'] === null)) {
            drupal_set_message(t('Please enter your last name.'), 'error');
            return;
        }

        if (($form_state['values']['email'] == '' || $form_state['values']['email'] === null) || !valid_email_address($form_state['values']['email'])) {
            drupal_set_message(t('Please enter a valid email address.'), 'error');
            return;
        }

        /////////////////////////////
        $userrequest = $_SESSION['agreservationuserrequest'];
        $selectedunittypenid = $userrequest['selectedunittypenid'];
        $selectedunittype = node_load($userrequest['selectedunittypenid']);
        $cat = node_load($userrequest['catnid']);
        $langbm = 'und';
        $langbm = field_language('node', $cat, 'field_agres_bookingmode');
        $selcapacity = 4;
        $langcap = field_language('node', $selectedunittype, 'field_agreservations_capacity');
        $selcapacity = $selectedunittype->field_agreservations_capacity[$langcap][0]['value'];
//***************************************Reservation******************************
        if ($cat->field_agres_bookingmode[$langbm][0]['value'] == '3') {
            //take into account the unpublished reservations from this very session:
            $res = null;
            if (isset($_SESSION['agreservationuserrequest']['resnid'])) {
                $res = node_load($_SESSION['agreservationuserrequest']['resnid']);
                if (isset($res) && $res !== false && res !== null && $res->status == 0) {
                    _agreservations_setstatus_reservation($_SESSION['agreservationuserrequest']['resnid'], TRUE);
                    $_SESSION['agreservationuserrequest']['tmppublished'] = '1';
                }
            }
            $userrequestunit = array();
            $userrequestunit[]['selectunittype'] = $selectedunittypenid;
            $unitsToBook = false;
            $currentpackage = node_load($_SESSION['agreservationuserrequest']['packagenid']);
            $reservable_units = agreservations_get_reservable_items('agreservations_unit', $_SESSION['agreservationuserrequest']['checkintime'], $_SESSION['agreservationuserrequest']['checkouttime'], $_SESSION['agreservationuserrequest']['catnid']);
//            drupal_set_message('<pre>reservables: ' . print_r($reservable_units, true) . '   </pre>');
            $langcode = field_language('node', $currentpackage, 'field_agr_pack_units');

            foreach ($reservable_units as $reskey => $resunit) {
                if (in_multi_assoc_array($resunit->nid, $currentpackage->field_agr_pack_units[$langcode])) {
                    $_SESSION['agreservationuserrequest']['packagenid'] = $currentpackage->nid;
                    $unitsToBook[] = $resunit;
                    break; //just 1
                }
            }
            //  remember previous choosed package:
            $_SESSION['agreservationuserrequest']['updowngrade'] = array('mode' => 3,
                'prodoldnid' => $_SESSION['agreservationuserrequest']['packagenid'],
                'prodnewnid' => $_SESSION['agreservationuserrequest']['packagenid'], 'updown' => 0); //  


            if (count($unitsToBook) < 1 || $unitsToBook === false) {
//*********find Packages with selected pcikup and dropoff points:*********************************        
                //$packs = _agres_package_get_packages($_SESSION['agreservationuserrequest']['pickuppoint'], $_SESSION['agreservationuserrequest']['dropoffpoint']);
                $packs = _agres_package_get_packages_of_capacity($_SESSION['agreservationuserrequest']['pickuppoint'], $_SESSION['agreservationuserrequest']['dropoffpoint'], $selcapacity);
                // drupal_set_message('<pre>$packs$packs'.print_r($packs,true).'</pre>');           
                foreach ($packs as $packkey => $pack) {
                    $packprices[$packkey] = $pack->sell_price;
                }
                asort($packprices, SORT_NUMERIC);
                //hier anfangen:
                $unitsToBook = false;
                $unitsToBook = _find_same_level_avbl_packages($packs, $packprices, $currentpackage->sell_price, $userrequest['pickuppoint'], $userrequest['dropoffpoint']);
                if (is_array($unitsToBook)) {
                    $newpacakge = node_load($_SESSION['agreservationuserrequest']['packagenid']);
                    $_SESSION['agreservationuserrequest']['updowngrade']['updown'] = 0;
                    $_SESSION['agreservationuserrequest']['updowngrade']['prodnewnid'] = $_SESSION['agreservationuserrequest']['packagenid'];
                    drupal_set_message('<div class="agr_downgradepackagemessage">' . print_r(t('Sorry the selected car was not available, a different car of the same quality was selected: <div class="agr_downgradepackagetitle"> @new. </div>', array('@new' => $newpacakge->title)), true) . '</div>', 'error');
                } else {
                    $unitsToBook = false;
                    $unitsToBook = _find_next_higher_avbl_packages($packs, $packprices, $currentpackage->sell_price, $userrequest['pickuppoint'], $userrequest['dropoffpoint']);
                    if (is_array($unitsToBook)) {
                        $prevpackage = node_load($_SESSION['agreservationuserrequest']['prev_upgrade_prodnid']); //agr_get_field_value_from_node_id($_SESSION['agreservationuserrequest']['prev_upgrade_prodnid'],'title');
//              drupal_set_message('<pre>'.print_r($prevpackage,true).'</pre>');
                        $newpacakge = node_load($_SESSION['agreservationuserrequest']['packagenid']);
                        $_SESSION['agreservationuserrequest']['updowngrade']['updown'] = 1;
                        $_SESSION['agreservationuserrequest']['updowngrade']['prodnewnid'] = $_SESSION['agreservationuserrequest']['packagenid'];
                        drupal_set_message('<div class="agr_upgradecarmessage">' . print_r(t('Sorry the selected car was not available, you have been upgraded for') . '<span class="free">' . t(' free ') . '</span>' . t('to') . t('<div class="agr_upgradecartitle"> @new. </div>', array('@new' => $newpacakge->title)), true) . '</div>', 'error');
                    } else {
                        $unitsToBook = false;
                        $unitsToBook = _find_next_lower_avbl_packages($packs, $packprices, $currentpackage->sell_price, $userrequest['pickuppoint'], $userrequest['dropoffpoint']);
                        //find next lower:         
                        if (!$unitsToBook) {
                            drupal_set_message('<div class="agr_noavailablesfound">' . t('Sorry, no available vehicles were found. Please make a different choice!') . '</div>', 'error');
                            $form_state['redirect'] = 'agrbookingstep1/' . $userrequest['catnid'] . '/' . $userrequest['resformtitel'] . '/' . $userrequest['datstring'];
//                 $form_state['redirect'] = '';
                        } else {
                            $newpacakge = node_load($_SESSION['agreservationuserrequest']['packagenid']);
                            $_SESSION['agreservationuserrequest']['updowngrade']['updown'] = -1;
                            $_SESSION['agreservationuserrequest']['updowngrade']['prodnewnid'] = $_SESSION['agreservationuserrequest']['packagenid'];
                            drupal_set_message('<div class="agr_downgradepackagemessage">' . print_r(t('Sorry the selected car was not available, you have been downgraded for the lower price - 10% to <div class="agr_downgradepackagetitle"> @new. </div>', array('@new' => $newpacakge->title)), true) . '</div>', 'error');
                        }
                    }
                }
            }
            if ((is_array($unitsToBook)) && (count($unitsToBook) > 0)) {
                if (isset($res) && $res !== false && $res !== null) {
//                 drupal_set_message('<pre>call::_agreservations_update_Reservation:::'.print_r($unitsToBook,true).'</pre>');
                    $resnid = _agreservations_update_Reservation($_SESSION['agreservationuserrequest']['resnid'], $unitsToBook);
                } else {
                    $resnid = _agreservations_create_Reservation($unitsToBook, $userrequest['checkintime'], $userrequest['checkouttime'], NULL, NULL, AGRES_STATUS_ONLINE_NO_ORDER_YET, t('Reservation'), 0);
                    $_SESSION['agreservationuserrequest']['resnid'] = $resnid;
                }
            } else {
                drupal_set_message(t('Sorry, no units available.'), 'error');
                drupal_goto('agrbookingstep1/' . $userrequest['catnid'] . '/' . $userrequest['resformtitel'] . '/' . $userrequest['datstring']);
            }
        } elseif ($cat->field_agres_bookingmode[$langbm][0]['value'] == '4') {
//*************************************************by the hour booking:********************************
//*****************************************************************************************************     
            $userrequestunit = array();
            $userrequestunit[]['selectunittype'] = $selectedunittypenid;
            $selectedunittype = node_load($selectedunittypenid);
            //take into account the unpublished reservations from this very session:
            $res = null;
            if (isset($_SESSION['agreservationuserrequest']['resnid'])) {
                $res = node_load($_SESSION['agreservationuserrequest']['resnid']);
                if (isset($res) && $res !== false && $res !== null && $res->status == 0) {
//                _agreservations_setstatus_reservation($_SESSION['agreservationuserrequest']['resnid'], TRUE);
//                $_SESSION['agreservationuserrequest']['tmppublished'] = '1';
                }
            }
//        drupal_set_message('<pre>uuuuuuuuuuuuuuuuuuuuuud'.print_r($res,true).'</pre>');
//***************************************************************************************
            $unitsToBook = false;
            $reservable_units = agreservations_get_reservable_items('agreservations_unit', $userrequest['checkintime'], $userrequest['checkouttime'], $userrequest['catnid']);
            $reservable_unittypes = _agreservations_get_reservable_unittypes($reservable_units, true);
            if (array_key_exists($selectedunittype->nid, $reservable_unittypes)) {
                $userrequestunit = array();
                $userrequestunit[]['selectunittype'] = $selectedunittype->nid;
                $unitsToBook = _agreservations_find_units_for_user_request($userrequestunit, $userrequest['checkintime'], $userrequest['checkouttime'], $userrequest['catnid']);
            }
//***************************************************************************************    
//  remember previous choosed unittype:
            $_SESSION['agreservationuserrequest']['updowngrade'] = array('mode' => 4,
                'prodoldnid' => $_SESSION['agreservationuserrequest']['selectedunittypenid'],
                'prodnewnid' => $_SESSION['agreservationuserrequest']['selectedunittypenid'], 'updown' => 0);

            if (count($unitsToBook) < 1 || $unitsToBook === false) {
                $orderedunittypes = _agres_categories_get_priceordered_products_with_capacity($userrequest['catnid'], $selcapacity);
                //$orderedunittypes = _agres_categories_get_priceordered_products($userrequest['catnid']);
                $unitsToBook = false;
                $unitsToBook = _find_same_level_avbl_unittypes($orderedunittypes, $selectedunittype->sell_price, $userrequest['checkintime'], $userrequest['checkouttime'], $userrequest['catnid']);
                if (is_array($unitsToBook)) {
                    $newprod = node_load($_SESSION['agreservationuserrequest']['selectedunittypenid']);
                    $_SESSION['agreservationuserrequest']['updowngrade']['updown'] = 0;
                    $_SESSION['agreservationuserrequest']['updowngrade']['prodnewnid'] = $_SESSION['agreservationuserrequest']['selectedunittypenid'];
                    drupal_set_message('<div class="agr_upgradecarmessage">' . print_r(t('Sorry the selected car was not available, a different car of the same price was selected: <div class="agr_upgradecartitle"> @new. </div>', array('@new' => $newprod->title)), true) . '</div>', 'error');
                } else {
                    $unitsToBook = false;
                    //remember previous selected unittype:        
                    $unitsToBook = _find_next_higher_avbl_unittypes($orderedunittypes, $selectedunittype->sell_price, $userrequest['checkintime'], $userrequest['checkouttime'], $userrequest['catnid'], 2);
                    if (is_array($unitsToBook)) {
                        $newprod = node_load($_SESSION['agreservationuserrequest']['selectedunittypenid']);
                        $_SESSION['agreservationuserrequest']['updowngrade']['updown'] = 1;
                        $_SESSION['agreservationuserrequest']['updowngrade']['prodnewnid'] = $_SESSION['agreservationuserrequest']['selectedunittypenid'];
                        drupal_set_message('<div class="agr_upgradecarmessage">' . print_r(t('Sorry the selected car was not available, you have been upgraded for') . '<span class="free">' . t(' free ') . '</span>' . t('to') . t('<div class="agr_upgradecartitle"> @new. </div>', array('@new' => $newprod->title)), true) . '</div>', 'error');
                    } else {
                        $unitsToBook = false;
                        $unitsToBook = _find_next_lower_avbl_unittypes($orderedunittypes, $selectedunittype->sell_price, $userrequest['checkintime'], $userrequest['checkouttime'], $userrequest['catnid'], 2);
                        //find next lower:         
                        if (!$unitsToBook) {
                            drupal_set_message(t('Could not find a unit for the selected type of car! Please make a different choice!'), 'error');
                            $form_state['redirect'] = 'agrbookingstep1/' . $userrequest['catnid'] . '/' . $userrequest['resformtitel'] . '/' . $userrequest['datstring'];
                        } else {
                            $newprod = node_load($_SESSION['agreservationuserrequest']['selectedunittypenid']);
                            $_SESSION['agreservationuserrequest']['updowngrade']['updown'] = -1;
                            $_SESSION['agreservationuserrequest']['updowngrade']['prodnewnid'] = $_SESSION['agreservationuserrequest']['selectedunittypenid'];
                            drupal_set_message('<div class="agr_downgradepackagemessage">' . print_r(t('Sorry the selected car was not available, you have been downgraded for the lower price - 10% to <div class="agr_downgradepackagetitle"> @new. </div>', array('@new' => $newprod->title)), true) . '</div>', 'error');
                        }
                    }
                }
            }
//        drupal_set_message('<pre>agres_categories_get_details_form_validate:::++fdd++----'. print_r($unitsToBook, true) . '</pre>');             
            if ((is_array($unitsToBook)) && (count($unitsToBook) > 0)) {
                if (isset($res) && $res !== false && $res !== null) {
//                 drupal_set_message('<pre>call::_agreservations_update_Reservation:::'.print_r($unitsToBook,true).'</pre>');
                    $resnid = _agreservations_update_Reservation($_SESSION['agreservationuserrequest']['resnid'], $unitsToBook);
                } else {
                    $resnid = _agreservations_create_Reservation($unitsToBook, $userrequest['checkintime'], $userrequest['checkouttime'], NULL, NULL, AGRES_STATUS_ONLINE_NO_ORDER_YET, t('Reservation'), 0);
                    $_SESSION['agreservationuserrequest']['resnid'] = $resnid;
                }
            } else {
                drupal_set_message(t('Sorry, no units available.'), 'error');
            }
        }
///*************************************************************************************
///*************************************************************************************    
///*************************************************************************************
        $capacity_reservation = 0;
//      drupal_set_message('<pre>_UNITSTOBOOK: ' . print_r($capacity_reservation, true) . '   </pre>'); 
        $capacity_reservation = _agreservations_get_capacity_from_reservation($_SESSION['agreservationuserrequest']['resnid']);
        if (intval($form_state['values']['numberpersons']) > intval($capacity_reservation)) {
            drupal_set_message('<div class="agr_exceedpassenger">' . t('The number of Passengers you selected exceed the available space! Please choose a different vehicle.') . '</div>', 'error');
            //choose additional unit but before add to cart this one so it does not get forgotton
            //there needs to be implemented a more modern way of doing this in the future...OOP needed.
            $packagenode = node_load($_SESSION['agreservationuserrequest']['packagenid']);
            $emptyform = array();
            _agres_bookings_reserve_and_fillcart($resnid, null, $userrequest, $userrequest['catnid'], $userrequest['selectedunittypenid'], array(), '', $emptyform);
            ////////////////////////////////////////////////////////////////////////////////////////////
            $_SESSION['agreservationuserrequest']['secondchoice'] = 1;
            $_SESSION['agreservationuserrequest']['redirect'] = 'agrbookingstep1/' . $userrequest['catnid'] . '/' . $userrequest['resformtitel'] . '/' . $userrequest['datstring'];
            $form_state['redirect'] = 'agrbookingstep1/' . $userrequest['catnid'] . '/' . $userrequest['resformtitel'] . '/' . $userrequest['datstring'];
            return;
        } else {
            $form_state['redirect'] = 'cart';
            $_SESSION['agreservationuserrequest']['redirect'] = 'cart';
        }

        $tmpDateCheckin = date_create($userrequest['checkintime']);
        $tmpDateCheckout = date_create($userrequest['checkintime']);
        //special for package booking mode:
    }

    //call this inside hook_form_submit
    static function _agr_get_details_form_submit($form, &$form_state) {
        //save form entry field values in the session: 
//    drupal_set_message('<pre>_agr_get_details_form_submit_agr_get_details_form_submit: ' . print_r($form_state['values'], true) . '   </pre>'); 
        //only if $form_state['redirect']='cart'; only then validation succeeded:
        if ($form_state['redirect'] == 'cart') {
            $_SESSION['agreservationuserrequest']['numberpassengers'] = $form_state['values']['numberpersons'];
            $_SESSION['agreservationuserrequest']['firstname'] = $form_state['values']['firstname'];
            $_SESSION['agreservationuserrequest']['lastname'] = $form_state['values']['lastname'];
            $_SESSION['agreservationuserrequest']['email'] = $form_state['values']['email'];
            if (isset($_SESSION['agreservationuserrequest']['firstname'])) {
                $firstname = $_SESSION['agreservationuserrequest']['firstname'];
            }
            if (isset($_SESSION['agreservationuserrequest']['lastname'])) {
                $lastname = $_SESSION['agreservationuserrequest']['lastname'];
            }
            if (isset($_SESSION['agreservationuserrequest']['email'])) {
                $email = $_SESSION['agreservationuserrequest']['email'];
            }
            $userrequest = $_SESSION['agreservationuserrequest'];
            if (module_exists('agr_additional_infos')) {
                $resnid = _agres_additional_infos_update_userrequestdata_to_Reservation($userrequest['resnid'], $userrequest);
            }

            $selectedunittypenid = $_SESSION['agreservationuserrequest']['selectedunittypenid'];
            $selectedunittype = node_load($selectedunittypenid);

            $cat = node_load($userrequest['catnid']);

            $langbm = 'und';
            $langbm = field_language('node', $cat, 'field_agres_bookingmode');
            $tmpDateCheckin = date_create($userrequest['checkintime']);
            $tmpDateCheckout = date_create($userrequest['checkintime']);
            // special for package booking mode:
            $langc = 'und';
            $langc = field_language('node', $selectedunittype, 'field_agreservations_capacity');
//  $_SESSION['agreservationuserrequest']['capacity']+=$selectedunittype->field_agreservations_capacity[$langc][0]['value'];    
            if (isset($userrequest['packagenid'])) {//           
                $packagenode = node_load($userrequest['packagenid']);
                $langh = 'und';
                $langh = field_language('node', $packagenode, 'field_agr_pack_hours');
                $hours = $packagenode->field_agr_pack_hours[$langh][0]['value'];
                $tmpDateCheckout = $tmpDateCheckout->modify('+' . $hours + 1 . ' hours');
                $userrequest['checkouttime'] = $tmpDateCheckout->format('Y-m-d H:i:s');
                $emptyform = array();
                _agres_bookings_reserve_and_fillcart($_SESSION['agreservationuserrequest']['resnid'], null, $userrequest, $userrequest['catnid'], $userrequest['selectedunittypenid'], array(), '', $emptyform);
            } else {
                $tmpDateCheckout = date_create($userrequest['checkouttime']);
                $emptyform = array();
                _agres_bookings_reserve_and_fillcart($_SESSION['agreservationuserrequest']['resnid'], null, $userrequest, $userrequest['catnid'], $userrequest['selectedunittypenid'], array(), '', $emptyform);
            }
//    drupal_set_message('<pre>reeeeeeeeeeeeeeedirect:::++++___' . print_r($form_state['redirect'], true) . '</pre>');
            if (isset($_SESSION['agreservationuserrequest']['redirect'])) {
                $form_state['redirect'] = $_SESSION['agreservationuserrequest']['redirect'];
            } else {
                $form_state['redirect'] = 'cart';
            }
        }
//  drupal_set_message('<pre>reeeeeeeeeeeeeeedirect:::++++___' . print_r($form_state['redirect'], true) . '</pre>');
//   
//      drupal_goto('cart');
    }

    static function _agr_onorder_searchwidget_form($pcat, &$form, &$form_state) {
        $cat = $pcat;
        $lang = 'und';
        $lang = field_language('node', $cat, 'field_agres_datelabel1');
        $datform_default = date_default_format('date_popup');
        $datform = str_replace(':s', '', $datform_default);
        $datform = 'Y-m-d';
//  $datform = str_replace('H:i','', $datform);
//  $datform = str_replace('H:i:s','', $datform);
//  $datform .= ' H:i';
        $langbm = 'und';
        $langbm = field_language('node', $cat, 'field_agres_bookingmode');

        if (!isset($form_state['unitsearch' . $cat->nid]['step']) || empty($form_state['unitsearch' . $cat->nid]['step'])) {
            // we are coming in without a step, so default to step 0
            $form_state['unitsearch' . $cat->nid]['step'] = 0;
        }

        $langcode_cn = 'und';
        $langcode_cn = field_language('node', $cat, 'field_agres_catname');
        $langcode_ap = 'und';
        $langcode_ap = field_language('node', $cat, 'field_agres_askpersons');
        if (isset($form_state['unitsearch' . $cat->nid]['errormsg'])) {
            drupal_set_message($form_state['unitsearch' . $cat->nid]['errormsg'], 'error');
        }

        switch ($form_state['unitsearch' . $cat->nid]['step']) {
            case 0:
                $form['unitsearch' . $cat->nid]['checkin'] = array(
                    '#id' => 'onorder-edit-checkin' . $cat->nid,
                    '#parents' => array('unitsearch' . $cat->nid, 'checkin'),
                    '#title' => $cat->field_agres_datelabel1[$lang][0]['safe_value'],
                    '#type' => 'date_popup',
                    '#required' => false,
                    '#date_type' => DATE_DATETIME,
                    '#date_timezone' => date_default_timezone(),
                    '#default_value' => date("Y-m-d", time()),
                    '#date_format' => $datform,
                    //    '#date_increment' => 1,
                    '#date_year_range' => '-1:+1',
                    '#datepicker_options' => array('minDate' => '-1Y'),
                    '#weight' => 100,
                );


                $timeoptions = _agres_categories_create_options_servicehours(0, $cat);
                $lang = 'und';
                $lang = field_language('node', $cat, 'field_agres_showtime');
                if (($cat->field_agres_showtime[$lang][0]['value'] == 1) || ($cat->field_agres_showtime[$lang][0]['value'] == 2)) {

//      drupal_set_message('<pre>categorie::::'.print_r($cat->nid,true).'</pre>');
                    $form['unitsearch']['checkin' . $cat->nid]['checkintime'] = array(
//      '#prefix' => '<div>',
                        '#type' => 'select',
                        '#title' => 'time', //$category->title . ' ' . t('count'), //t('Units'),
                        '#default_value' => reset($timeoptions),
                        '#options' => $timeoptions,
//      '#suffix' => '</div>',
                        '#weight' => 150,
                    );
//    $datform .= ' H:i';
                }
                $lang = 'und';
                $lang = field_language('node', $cat, 'field_agres_datelabel2');

                $timeoptions1 = _agres_categories_create_options_servicehours(0, $cat);
                $lang = 'und';
                $lang = field_language('node', $cat, 'field_agres_showtime');
                if (isset($cat->field_agres_datelabel2[$lang][0]['safe_value'])) {
                    $form['unitsearch' . $cat->nid]['checkout'] = array(
                        '#id' => 'onorder-edit-checkout' . $cat->nid,
                        '#parents' => array('unitsearch' . $cat->nid, 'checkout'),
                        '#title' => $cat->field_agres_datelabel2[$lang][0]['safe_value'],
                        '#type' => 'date_popup',
                        '#required' => false,
                        '#date_type' => DATE_DATETIME,
                        '#date_timezone' => date_default_timezone(),
                        '#default_value' => date("Y-m-d", time()),
                        '#date_format' => $datform,
//    '#date_increment' => 1,
                        '#date_year_range' => '-1:+1',
                        '#datepicker_options' => array('minDate' => '-1Y'),
                        '#weight' => 200,
                    );
                    if ($cat->field_agres_showtime[$lang][0]['value'] > 0) {
                        //
                        $form['unitsearch' . $cat->nid]['checkout']['checkouttime'] = array(
                            //      '#prefix' => '<div>',
                            '#type' => 'select',
                            '#title' => 'time', //$category->title . ' ' . t('count'), //t('Units'),
                            '#default_value' => reset($timeoptions1),
                            '#options' => $timeoptions1,
                            //      '#suffix' => '</div>',
                            '#weight' => 250,
                        );
                        $datform .= ' H:i';
                    }
                } elseif (($cat->field_agres_showtime[$lang][0]['value'] == 3) || ($cat->field_agres_showtime[$lang][0]['value'] == 1)) {
                    $form['unitsearch' . $cat->nid]['checkin']['checkouttime'] = array(
                        //      '#prefix' => '<div>',
                        '#type' => 'select',
                        '#title' => 'time', //$category->title . ' ' . t('count'), //t('Units'),
                        '#default_value' => reset($timeoptions1),
                        '#options' => $timeoptions1,
                        //      '#suffix' => '</div>',
                        '#weight' => 200,
                    );
                    $datform .= ' H:i';
                }
                $langnu = 'und';
                $langnu = field_language('node', $cat, 'field_agres_shownumberunits');
                if ($cat->field_agres_shownumberunits[$lang][0]['value'] == 1) {
                    $lang = 'und';
                    $lang = field_language('node', $cat, 'field_agres_unitslabel');
                    if (isset($cat->field_agres_unitslabel[$lang])) {
                        $title = $cat->field_agres_unitslabel[$lang][0]['safe_value'];
                    } else {
                        $title = t('units');
                    }
                    $lang = 'und';
                    $lang = field_language('node', $cat, 'field_agres_numberunits');

                    $form['unitsearch' . $cat->nid]['units'] = array(
//      '#prefix' => '<div>',
                        '#type' => 'select',
                        '#title' => $title, //$category->title . ' ' . t('count'), //t('Units'),
                        '#default_value' => $cat->field_agres_numberunits[$langnu][0]['value'],
                        '#options' => array(
                            1 => 1,
                            2 => 2,
                            3 => 3,
                            4 => 4,
                            5 => 5,
                            6 => 6,
                            7 => 7,
                            8 => 8,
                            9 => 9,
                            10 => 10,
                        ),
//      '#suffix' => '</div>',
                        '#weight' => 300,
                    );
                }
//      $form['unitsearch'.$cat->nid]['agrunittypeselect'.$cat->nid] = array(
//        '#tree' => TRUE,
//        '#prefix' => '<div id="agrunittypeselect'.$cat->nid.'">',
//        '#suffix' => '</div>',
////          '#markup' => '<h1>Initial markup for box</h1>'
//      );
//        $form['unitsearch'.$cat->nid]['wrapp'] = array(
//      '#prefix' => '<div id="makechoice">',
//      '#suffix' => '</div>',
//    );
                $form['unitsearch' . $cat->nid]['submit'] = array(
//    '#prefix' => '<div>',
                    '#type' => 'submit',
                    '#title' => 'Search',
                    '#value' => t('Search'),
                    '#submit' => array('_agres_bm_2_order_unitsearch_submit'),
                    '#name' => $cat->nid,
                    '#ajax' => array(
                        'callback' => '_agr_bm_2_order_searchcallback',
//            'path' => 'agr_order_add_res/'.$cat->nid,
                        'wrapper' => 'unittypesearch' . $cat->nid,
//            'wrapper' => 'agrunittypeselect'.$cat->nid,
                        'progress' => array(
                            'type' => 'throbber',
                        ),
                    ),
//         '#submit' => array('agres_categories_searchwidget_form_submit'),
//    '#suffix' => '</div>',
                    '#weight' => 500,
                );
                break;
            case 1:
//        drupal_set_message('<pre>agres_bookings_multi_forms__222222_:'.print_r($cat->nid,true).'</pre>');
                $langm = field_language('node', $cat, 'field_agres_measuringunit');
                $measureingunit = $cat->field_agres_measuringunit[$langm][0]['value'];
                $form['unitsearch' . $cat->nid]['agres_info'] = array(
                    '#type' => 'markup',
                    '#value' => '<div><b>' . t('From: %checkin to %checkout', array('%checkin' => $form_state['values']['checkin' . $cat->nid], '%checkout' => $form_state['values']['checkin' . $cat->nid]))
                    . '</b></div>',
                    '#weight' => 444,
                );
                $form['unitsearch' . $cat->nid]['checkin'] = array('#type' => 'hidden', '#value' => $form_state['values']['checkin' . $cat->nid]);
                $form['unitsearch' . $cat->nid]['checkout'] = array('#type' => 'hidden', '#value' => $form_state['values']['checkout' . $cat->nid]);

                $form['unitsearch' . $cat->nid]['agres_info'] = array(
                    '#tree' => TRUE,
//        '#prefix' => '<div id="agrunittypeselect'.$cat->nid.'">',
//        '#suffix' => '</div>',
                    '#markup' => '<div><b>' . t('From: %checkin', array('%checkin' => $form_state['values']['checkin' . $cat->nid],)) . '</br>'
                    . t('To: %checkout', array('%checkout' => $form_state['values']['checkout' . $cat->nid],)) . '</b></div>',
                );
                $availableunittypes = $form_state['unitsearch' . $cat->nid]['available_unittypes'];
                $locoptions = array();
                foreach ($availableunittypes as $availableunittype) {
                    $langcode_au = 'und';
                    $langcode_au = field_language('node', $availableunittype['rtnode'], 'field_agreservations_capacity');
                    if (!isset($availableunittype['rtnode']->field_agreservations_capacity[$langcode_au])) {
                        $langcode_au = 'und';
                    }

                    $locoptions[$availableunittype['rtnode']->nid] = $availableunittype['rtnode']->title . ' ' . t('Capacity: ')
                            . $availableunittype['rtnode']->field_agreservations_capacity[$langcode_au][0]['value']; // . ' ' . t('Price: ') . uc_store_format_price_field_value($availableunittype['rtnode']->sell_price);
                }
                $form['unitsearch' . $cat->nid]['unitinfo'] = array(
                    '#type' => 'fieldset',
                    '#title' => $cat->field_agres_catname[$langcode_cn][0]['value'] . ' ' . t('Informations:'),
                    '#collapsible' => FALSE,
                    '#tree' => TRUE,
                ); //$userrequest['requestedunits']
                $intvunits = intval($form_state['values']['unitsearch' . $cat->nid]['units']);
                for ($i = 1; $i <= $intvunits; $i++) {
                    $form['unitsearch' . $category->nid]['unitinfo'][$i] = array(
                        '#type' => 'fieldset',
                        '#title' => $cat->field_agres_catname[$langcode_cn][0]['safe_value'] . ' ' . $i,
                        '#collapsible' => FALSE,
                        '#tree' => TRUE,
                    );
                    /*                     * ************************************************************************************************ */
//                    $tmpagres_onlineformjelements = variable_get('agres_onlineformjelements', 'standard');
//                    $form_state['build_info']['values'] = array();
                    if (($cat->field_agres_askpersons[$langcode_ap][0]['value'] == 1) || ($cat->field_agres_askpersons[$langcode_ap][0]['value'] == 3)) {
                        $form['unitsearch' . $cat->nid]['unitinfo'][$i]['adults'] = array(
                            '#prefix' => '<div>',
                            '#type' => 'select',
                            '#title' => t('Persons'),
                            '#default_value' => 1, //agres_categories_dv($form_state['build_info']['values'][1]['unitinfo'][$i]['adults']),
                            '#options' => array(
                                1 => 1,
                                2 => 2,
                                3 => 3,
                                4 => 4,
                                5 => 5,
                                6 => 6,
                                7 => 7,
                                8 => 8,
                                9 => 9,
                                10 => 10,
                            ),
                            '#suffix' => '</div>',
                        );
                    }
                    /*                     * *********************************************************************************************** */
                    $selectedunitnid = key($locoptions); //agres_onlineformj_dv($form_state['storage']['values'][1]['unitinfo'][$i]['selectunittype']);

                    $selectedunitnode = node_load($selectedunitnid, NULL, TRUE);
                    $form['unitsearch' . $cat->nid]['unitinfo'][$i]['selectunittype'] = array(
                        '#type' => 'select',
                        '#title' => t('Type of') . ' ' . $cat->field_agres_catname[$langcode_cn][0]['safe_value'],
                        //            '#default_value' => agres_categories_dv($form_state['build_info']['values'][1]['unitinfo'][$i]['selectunittype']), //variable_get('feed_item_length','teaser'),
                        '#options' => $locoptions,
                        '#description' => t('select the') . ' ' . $cat->field_agres_catname[$langcode_cn][0]['safe_value'] . ' ' . t('type'),
                        '#suffix' => '<div id="wrapper-' . $i . '"> </div>',
//                        '#ajax' => array(
//                            'event' => 'change',
//                            'path' => 'agres-categoriesformj-callback/' . $i,
//                            'wrapper' => 'wrapper-' . $i,
//                            'method' => 'replace',
//                        ),
                    );
                }
                $form['unitsearch' . $cat->nid]['cancel'] = array(
                    //    '#prefix' => '<div>',
                    '#id' => 'back-' . $cat->nid,
                    '#type' => 'submit',
                    '#title' => 'back',
                    '#value' => 'back',
                    '#submit' => array('_agres_bm_2_order_unittype_backsubmit'),
                    '#name' => $cat->nid,
                    '#ajax' => array(
                        'callback' => '_agr_bm_2_order_searchcallback',
                        'event' => 'click',
                        //            'path' => 'agr_order_add_res/'.$cat->nid,
                        'wrapper' => 'unittypesearch' . $cat->nid,
                        //            'wrapper' => 'agrunittypeselect'.$cat->nid,
                        'progress' => array(
                            'type' => 'throbber',
                        ),
                    ),
                    //         '#submit' => array('agres_categories_searchwidget_form_submit'),
                    //    '#suffix' => '</div>',
                    '#weight' => 300,
                );
                $form['unitsearch' . $cat->nid]['book'] = array(
                    //    '#prefix' => '<div>',
                    '#id' => 'book-' . $cat->nid,
                    '#type' => 'submit',
                    '#title' => 'book',
                    '#value' => 'book',
                    '#submit' => array('_agres_bm_2_order_unittype_booksubmit'),
                    '#name' => $cat->nid,
                    '#ajax' => array(
                        'callback' => '_agr_bm_2_order_searchcallback',
                        'event' => 'click',
                        //            'path' => 'agr_order_add_res/'.$cat->nid,
                        'wrapper' => 'unittypesearch' . $cat->nid,
                        //            'wrapper' => 'agrunittypeselect'.$cat->nid,
                        'progress' => array(
                            'type' => 'throbber',
                        ),
                    ),
                    //         '#submit' => array('agres_categories_searchwidget_form_submit'),
                    //    '#suffix' => '</div>',
                    '#weight' => 301,
                );
                break;
        }


        if ($form_state['unitsearch' . $cat->nid]['step'] == 2) {
//           drupal_set_message('<pre>jajajajjajjjjaj'.print_r($form_state['build_info']['unitsearch'.$cat->nid]['step'],true).'</pre>');
            $form_state['unitsearch' . $cat->nid]['available_unittypes'];
        }


        return $form['unitsearch' . $cat->nid];
    }

    static function _agr_unittype_form($form, $form_state) {
//     drupal_set_message('<pre>_agr_unittype_form_agr_unittbcbcbype_form-fff--->'.print_r($form_state,true).'</pre>');

        $cat = $form_state['build_info']['args'][0];
        $unittypenid = $form_state['build_info']['args'][1];
//  drupal_set_message('<pre>agreservations_unittype_formcat '.print_r($catnid,true).'</pre>');
//  $cat = node_load($catnid);
        $langcode = i18n_langcode();
        if (!isset($cat->field_agres_showtime[$langcode]) || !isset($cat->field_agres_datelabel1[$langcode])) {
            $langcode = language_default('language');
            if (!isset($cat->field_agres_showtime[$langcode]) || !isset($cat->field_agres_datelabel1[$langcode])) {
                $langcode = 'und';
            }
        }
        $datform_default = date_default_format('date_popup');
        $datform = str_replace(':s', '', $datform_default);
        $datform = 'Y-m-d';
//    &&isset($cat->field_agres_showtime[$langcode])
        $form['unittypebook'] = array(
            '#type' => 'fieldset',
            '#tree' => TRUE,
//    '#title' => t('Name'),
        );
        $form['unittypebook']['checkin' . $cat->nid] = array(
//    '#prefix' => '<div>',
            '#type' => 'agr_datepicker',
            '#tree' => TRUE,
            '#title' => $cat->field_agres_datelabel1[$langcode][0]['safe_value'],
            '#required' => TRUE,
            '#date_label_position' => 'within',
            '#size' => 10,
            '#description' => t(''),
            '#date_type' => 'datetime',
            '#date_timezone' => date_default_timezone(), //Y-m-d H:i
            '#date_format' => $datform,
            '#date_year_range' => '-0:+1',
//    '#suffix' => '</div>',
        );

        $timeoptions = Array
            ('00:00' => '00:00',
            '00:15' => '00:15',
            '00:30' => '00:30',
            '00:45' => '00:45',
            '01:00' => '01:00',
            '01:15' => '01:15',
            '01:30' => '01:30',
            '01:45' => '01:45',
            '02:00' => '02:00',
            '02:15' => '02:15',
            '02:30' => '02:30',
            '02:45' => '02:45',
            '03:00' => '03:00',
            '03:15' => '03:15',
            '03:30' => '03:30',
            '03:45' => '03:45',
            '04:00' => '04:00',
            '04:15' => '04:15',
            '04:30' => '04:30',
            '04:45' => '04:45',
            '05:00' => '05:00',
            '05:15' => '05:15',
            '05:30' => '05:30',
            '05:45' => '05:45',
            '06:00' => '06:00',
            '06:15' => '06:15',
            '06:30' => '06:30',
            '06:45' => '06:45',
            '07:00' => '07:00',
            '07:15' => '07:15',
            '07:30' => '07:30',
            '07:45' => '07:45',
            '08:00' => '08:00',
            '08:15' => '08:15',
            '08:30' => '08:30',
            '08:45' => '08:45',
            '09:00' => '09:00',
            '09:15' => '09:15',
            '09:30' => '09:30',
            '09:45' => '09:45',
            '10:00' => '10:00',
            '10:15' => '10:15',
            '10:30' => '10:30',
            '10:45' => '10:45',
            '11:00' => '11:00',
            '11:15' => '11:15',
            '11:30' => '11:30',
            '11:45' => '11:45',
            '12:00' => '12:00',
            '12:15' => '12:15',
            '12:30' => '12:30',
            '12:45' => '12:45',
            '13:00' => '13:00',
            '13:15' => '13:15',
            '13:30' => '13:30',
            '13:45' => '13:45',
            '14:00' => '14:00',
            '14:15' => '14:15',
            '14:30' => '14:30',
            '14:45' => '14:45',
            '15:00' => '15:00',
            '15:15' => '15:15',
            '15:30' => '15:30',
            '15:45' => '15:45',
            '16:00' => '16:00',
            '16:15' => '16:15',
            '16:30' => '16:30',
            '16:45' => '16:45',
            '17:00' => '17:00',
            '17:15' => '17:15',
            '17:30' => '17:30',
            '17:45' => '17:45',
            '18:00' => '18:00',
            '18:15' => '18:15',
            '18:30' => '18:30',
            '18:45' => '18:45',
            '19:00' => '19:00',
            '19:15' => '19:15',
            '19:30' => '19:30',
            '19:45' => '19:45',
            '20:00' => '20:00',
            '20:15' => '20:15',
            '20:30' => '20:30',
            '20:45' => '20:45',
            '21:00' => '21:00',
            '21:15' => '21:15',
            '21:30' => '21:30',
            '21:45' => '21:45',
            '22:00' => '22:00',
            '22:15' => '22:15',
            '22:30' => '22:30',
            '22:45' => '22:45',
            '23:00' => '23:00',
            '23:15' => '23:15',
            '23:30' => '23:30',
            '23:45' => '23:45',
        );
        if (module_exists('agres_categories')) {
            $timeoptions = _agres_categories_create_options_servicehours(0, $cat);
//    drupal_set_message('<pre>timeoptions---->'.print_r($timeoptions,true).'</pre>');
        }

        $lang = 'und';
        $lang = field_language('node', $cat, 'field_agres_showtime');
        if ($cat->field_agres_showtime[$lang][0]['value'] > 0) {
            //
            $form['unittypebook']['checkin' . $cat->nid]['checkintime'] = array(
//      '#prefix' => '<div>',
                '#type' => 'select',
                '#title' => 'time', //$category->title . ' ' . t('count'), //t('Units'),
                '#default_value' => reset($timeoptions),
                '#options' => $timeoptions,
//      '#suffix' => '</div>',
                '#weight' => 150,
            );
//    $datform .= ' H:i';
        }

        if (isset($cat->field_agres_datelabel2[$langcode][0]['safe_value'])) {
            $form['unittypebook']['checkout' . $cat->nid] = array(
//      '#prefix' => '<div>',
                '#type' => 'agr_datepicker',
                '#tree' => TRUE,
                '#title' => $cat->field_agres_datelabel2[$langcode][0]['safe_value'],
                //      '#default_value' =>
                '#required' => TRUE,
                '#date_label_position' => 'within',
                '#size' => 10,
                '#date_type' => 'datetime',
                '#date_timezone' => date_default_timezone(),
                '#date_format' => $datform,
                '#date_year_range' => '-0:+1',
//      '#suffix' => '</div>',
            );
        }
        $lang = 'und';
        $lang = field_language('node', $cat, 'field_agres_showtime');
        if ($cat->field_agres_showtime[$lang][0]['value'] > 0) {
            //
            $form['unittypebook']['checkout' . $cat->nid]['checkouttime'] = array(
//      '#prefix' => '<div>',
                '#type' => 'select',
                '#title' => 'time', //$category->title . ' ' . t('count'), //t('Units'),
                '#default_value' => reset($timeoptions),
                '#options' => $timeoptions,
//      '#suffix' => '</div>',
                '#weight' => 150,
            );
//    $datform .= ' H:i';
        }
//  if ($cat->field_agres_shownumberunits[$langcode][0]['value'] == 1) {
        $form['unittypebook']['units'] = array(
            '#prefix' => '<div>',
            '#type' => 'select',
            '#title' => t('units'), //$category->title . ' ' . t('count'), //t('Units'),
            '#default_value' => $cat->field_agres_numberunits[$langcode][0]['value'],
            '#options' => array(
                1 => 1,
                2 => 2,
                3 => 3,
                4 => 4,
                5 => 5,
                6 => 6,
                7 => 7,
                8 => 8,
                9 => 9,
                10 => 10,
            ),
            '#suffix' => '</div>',
        );
//  }
        $form['unittype'] = array('#type' => 'value', '#value' => $unittypenid);

        $form['unittypebook']['submit'] = array(
            '#prefix' => '<div>',
            '#tree' => TRUE,
            '#type' => 'submit',
            '#title' => 'Book',
            '#value' => 'Book',
//     '#submit' => array('agres_categories_searchwidget_form_submit'),
//       '#submit' => array('_agr_unittype_form_submit'),
            '#suffix' => '</div>',
        );

        return $form;
    }

////*when anonymous users clicks search on the searchform:*/
//
    static function _agr_unittype_form_submit($form, &$form_state) {

        if (module_exists('uc_cart')) {
            if (isset($form_state['build_info']['args'][0])) {
                if (is_object($form_state['build_info']['args'][0])) {
                    $cat = $form_state['build_info']['args'][0];
                    $catid = $cat->nid;
                } else {
                    $catid = $form_state['build_info']['args'][0];
                    $cat = node_load($form_state['build_info']['args'][0]);
                }

                $preselectedunit = $form_state['values']['unittype'];
                drupal_set_message('<pre>UBERCART BUY IT NOW!' . print_r($preselectedunit, TRUE) . '</pre>');
                $langcode = i18n_langcode();
                $lang = 'und';
                $lang = field_language('node', $cat, 'field_agres_showtime');
                if (!isset($cat->field_agres_showtime[$lang]) || !isset($cat->field_agres_datelabel1[$lang])) {
                    $langcode = 'und';
                }
//    if (module_exists('uc_cart')) {
//      uc_cart_empty(uc_cart_get_id());
//    }

                if (isset($form_state['build_info']['args'][0])) {
                    $cat = $form_state['build_info']['args'][0];
                    if (isset($form_state['values']['adults'])) {
                        $adults = $form_state['values']['adults'];
                    }

                    if (isset($form_state['values']['children'])) {
                        $children = $form_state['values']['children'];
                    }

                    if (isset($form_state['values']['units'])) {
                        $requestedunits = $form_state['values']['units'];
                    }
//drupal_set_message('<pre>issetissetissetisset****'.print_r($form_state['input'],TRUE).'</pre>');
                    if (isset($form_state['input']['unittypebook']['checkin' . $catid])) {


                        if (isset($form_state['input']['unittypebook']['checkin' . $catid]['checkintime'])) {
                            $tmpDateCheckin = date_create($form_state['input']['unittypebook']['checkin' . $catid]['date'] . ' ' . $form_state['input']['unittypebook']['checkin' . $catid]['checkintime']);
                        } else {
                            $tmpDateCheckin = date_create($form_state['input']['unittypebook']['checkin' . $catid]);
                        }

//        drupal_set_message('<pre>$tmpDateCheckin$tmpDateCheckin****'.print_r($tmpDateCheckin,TRUE).'</pre>');
                    }
                    if (isset($form_state['input']['unittypebook']['checkout' . $catid])) {
                        if (isset($form_state['input']['unittypebook']['checkout' . $catid]['checkouttime'])) {
                            $tmpDateCheckout = date_create($form_state['input']['unittypebook']['checkout' . $catid]['date'] . ' ' . $form_state['input']['unittypebook']['checkout' . $catid]['checkouttime']);
                        } else {
                            $tmpDateCheckout = date_create($form_state['input']['unittypebook']['checkout' . $catid]);
                        }
                    }
//      if (($cat->field_agres_showtime[$lang][0]['value'] <> 1) && (isset($cat->field_agres_defaultcheckintime[$lang][0]['value']))) {
//        date_modify($tmpDateCheckin, $cat->field_agres_defaultcheckintime[$langcode][0]['value']);
//        date_modify($tmpDateCheckout, $cat->field_agres_defaultcheckouttime[$langcode][0]['value']);
//      }
                    $checkintime = date_format($tmpDateCheckin, 'Y-m-d H:i:s');
                    $checkouttime = date_format($tmpDateCheckout, 'Y-m-d H:i:s');


                    $resnodes = agreservations_get_reservable_items('agreservations_unit', date_format($tmpDateCheckin, 'Y-m-d H:i:s'), date_format($tmpDateCheckout, 'Y-m-d H:i:s'), $catid);

                    $availableunittypes = _agreservations_get_reservable_unittypes($resnodes, FALSE);
//    //Filter types:
                    $_SESSION['availableunittypes'] = $availableunittypes;
                    $foundunits = count($resnodes);
                    $userrequest['checkintime'] = $checkintime;
                    $userrequest['checkouttime'] = $checkouttime;
                    if (isset($adults)) {
                        $userrequest['adults'] = $adults;
                    }
                    if (isset($children)) {
                        $userrequest['children'] = $children;
                    }
                    //if ubercart exists then add to cart 1 unit of this unittype:
                    if (module_exists('uc_cart')) {
                        _agres_bookings_reserve_and_fillcart(null, null, $userrequest, $cat->nid, $preselectedunit, array(), 'cart', $form_state);
                    }
                } else {
                    $content = '<div>' . t('Category not set') . '</div>';
                    $content = $content . '<br><a href="' . base_path() . '">' . t('back') . '<a>';
                    print theme('page', $content);
                }
            } else {
                drupal_set_message('Category not set!');
            }
        } else {
//    drupal_set_message('<pre>nicht ubercart' . print_r($form_state, TRUE) . '</pre>');
        }
    }

///**
// * Implementation of hook validate():
// */
    static function _agr_unittype_form_validate($form, &$form_state) {

//       drupal_set_message('<pre>submit****'.print_r($form_state,true).'</pre>');
        $datform = 'Y-m-d H:i:s'; //:s
        if (isset($form_state['build_info']['args'][0])) {
            if (is_object($form_state['build_info']['args'][0])) {
                $cat = $form_state['build_info']['args'][0];
                $catnid = $cat->nid;
            } else {
                $catnid = $form_state['build_info']['args'][0];
                $cat = node_load($catnid);
//                $langcode = 'und';
//                $langcode = i18n_langcode(); 
            }

//                    drupal_set_message('<pre>_agr_unittype_form_validate' . print_r($form_state, TRUE) . '</pre>');
//    if (!isset($cat->field_agres_showtime[$langcode]) || !isset($cat->field_agres_datelabel1[$langcode])) {
//    }
//    drupal_set_message('<pre>cat****'.print_r($cat,true).'</pre>');
            if (!isset($form_state['input']['unittypebook']['units'])) {
                $form_state['input']['unittypebook']['units'] = 1;
            }
            $requestedunits = $form_state['input']['unittypebook']['units'];
            if (!isset($form_state['input']['unittypebook']['checkin' . $catnid]['date']) || ($form_state['input']['unittypebook']['checkin' . $catnid]['date'] == '')) {
                form_set_error('unitinfo', t('Checkout-time has to be entered'));
//      drupal_set_message('<pre>agreservations_unittype_form_validate****'.print_r($form_state,TRUE).'</pre>');
                return;
            } else {
//      drupal_set_message('<pre>agreservations_unittype_form_validate****'.print_r($form_state['values']['unittypebook']['checkin'],TRUE).'</pre>');

                $tmpDateCheckin = date_create($form_state['input']['unittypebook']['checkin' . $catnid]['date']);
            }
//    drupal_set_message('<pre>$tmpDateCheckin$tmpDateCheckin****'.print_r($tmpDateCheckin,TRUE).'</pre>');
            $langcode_csu = 'und';
            $langcode_csu = field_language('node', $cat, 'field_agres_shownumberunits');
            $langcode_cnu = 'und';
            $langcode_cnu = field_language('node', $cat, 'field_agres_numberunits');
            if (($cat->field_agres_shownumberunits[$langcode_csu][0]['value'] !== 1) && (isset($cat->field_agres_numberunits[$langcode_cnu][0]['value']))) {
                $form_state['input']['unittypebook']['units'] = $cat->field_agres_numberunits[$langcode_cnu][0]['value'];
            }
            $langcode_cdl2 = 'und';
            $langcode_cdl2 = field_language('node', $cat, 'field_agres_datelabel2');
            if (!isset($cat->field_agres_datelabel2[$langcode_cdl2][0]['value'])) {
//      drupal_set_message('<pre>hier</pre>');
                if (!isset($form_state['input']['unittypebook']['checkout' . $catnid])) {
                    form_set_error('unitinfo', t('Checkout-time has to be entered'));
                }
                $tmpDateCheckout = date_create($form_state['input']['unittypebook']['checkin' . $catnid]['date']);
            } else {
                if (!isset($form_state['input']['unittypebook']['checkout' . $catnid]) || ($form_state['input']['unittypebook']['checkout' . $catnid]['date'] == '')) {
                    form_set_error('unitinfo', t('Checkout-time has to be entered'));
                    return;
                }
                $tmpDateCheckout = date_create($form_state['input']['unittypebook']['checkout' . $catnid]['date']);
            }

            //check restrictions if modules is enabled:
            if (module_exists('agres_restriction') && (variable_get('agr_checkglobalrestriction_swidget', 'yes') == 'yes')) {
                $message = agres_timeframe_api('check_restrictions', array(
                    'start_date' => $form_state['values']['unittypebook']['checkin' . $catnid],
                    'end_date' => $form_state['values']['unittypebook']['checkout' . $catnid],
                ));
            }
            $langcode_cst = 'und';
            $langcode_cst = field_language('node', $cat, 'field_agres_showtime');
            $langcode_cdc = 'und';
            $langcode_cdc = field_language('node', $cat, 'field_agres_defaultcheckintime');
            $langcode_cdco = 'und';
            $langcode_cdco = field_language('node', $cat, 'field_agres_defaultcheckouttime');
//           drupal_set_message('<pre>agres_categories_searchwidget_form_validate****'.print_r($cat->field_agres_defaultcheckintime,TRUE).'</pre>');
            if (($cat->field_agres_showtime[$langcode_cst][0]['value'] !== 1) && (isset($cat->field_agres_defaultcheckintime[$langcode_cdc][0]['value']))) {

                date_modify($tmpDateCheckin, $cat->field_agres_defaultcheckintime[$langcode_cdc][0]['value']);
                $form_state['input']['unittypebook']['checkin' . $catnid] = $tmpDateCheckin->format($datform);
                date_modify($tmpDateCheckout, $cat->field_agres_defaultcheckouttime[$langcode_cdco][0]['value']);
                $form_state['input']['unittypebook']['checkout' . $catnid] = $tmpDateCheckout->format($datform);
            }
            $langcode_cdur = 'und';
            $langcode_cdur = field_language('node', $cat, 'field_agres_duration');
            //apply duration if set and only from: date is askedfor/entered by user:
            if (isset($cat->field_agres_duration[$langcode_cdur])) {
                if (($cat->field_agres_duration[$langcode_cdur][0]['approx_seconds'] > 0) && (!isset($cat->field_agres_datelabel2[$langcode_cdl2][0]['value']))) {
                    $tmpDateCheckout = date_create($form_state['values']['unittypebook']['checkin']);
                    date_modify($tmpDateCheckout, '+' . $cat->field_agres_duration[$langcode_cdur][0]['approx_seconds'] . ' second');
                    //write back to form_state:

                    $form_state['values']['unittypebook']['checkout'] = $tmpDateCheckout->format($datform);
                }
            }
            /*             * *******************check servicehours!****************************************************************** */
            $checkinisinrange = _agres_categories_check_servicehours($tmpDateCheckin, $cat);
            $checkoutisinrange = _agres_categories_check_servicehours($tmpDateCheckout, $cat);
            if ($checkinisinrange === FALSE) {
                form_set_error('unitinfo', t('Checkin-time has to be within service hours '));
            }
            if ($checkoutisinrange === FALSE) {
                form_set_error('unitinfo', t('Checkout-time has to be within service hours '));
            }

            if ($tmpDateCheckin >= $tmpDateCheckout) {
                form_set_error('unitinfo', t('Checkin has to be before Checkout '));
            }
            if ($tmpDateCheckin <= new DateTime()) {
                form_set_error('unitinfo', t('Checkin is has to be in the future !!! '));
            }
            $checkintime = date_format($tmpDateCheckin, 'Y-m-d H:i:s');
            $checkouttime = date_format($tmpDateCheckout, 'Y-m-d H:i:s');

            /* get reservable units: */
            $resnodes = agreservations_get_reservable_items('agreservations_unit', date_format($tmpDateCheckin, 'Y-m-d H:i'), date_format($tmpDateCheckout, 'Y-m-d H:i'), $cat);

            $foundunits = count($resnodes);
            if ($requestedunits > 0) {
                if ($requestedunits > $foundunits) {
                    form_set_error('unitinfo', t('Not enough free units found.'));
                }
            } elseif ($requestedunits == 0) {
                $langcode_cusel = 'und';
                $langcode_cusel = field_language('node', $cat, 'field_agres_unitselectionmethod');
                if (!($cat->field_agres_shownumberunits[$langcode_csu][0]['value'] == 2 && $cat->field_agres_unitselectionmethod[$langcode_cusel][0]['value'] == 2)) {
                    form_set_error('unitinfo', t('Number of units has to be > 0'));
                }
            }
            $tmpagres_onlineformjelements = variable_get('agres_onlineformjelements', 'standard');
        } else {
            form_set_error('unitinfo', t('agres_category not set! Please try again'));
        }
    }

    static function _agr_get_get_unitselect_form($category) {
        $userrequest = $_SESSION['agreservationuserrequest']; //unserialize($suserrequest);      
//    drupal_set_message('<pre>agres_bookings_select_unit_btn_form****__'.print_r($userrequest,true).'</pre>');     
        if (isset($category)) {
            $langcode = field_language('node', $category, 'field_agres_titleresform');
            $langcode = i18n_langcode();
            if (!isset($category->field_agres_titleresform[$langcode])) {
                $langcode = language_default('language');
                if (!isset($category->field_agres_titleresform[$langcode])) {
                    $langcode = 'und';
                }
            }
            $langcode_caus = field_language('node', $category, 'field_agres_unitselectionmethod');
            $langbm = field_language('node', $category, 'field_agres_bookingmode');
            if ($category->field_agres_bookingmode[$langbm][0]['value'] == '2') {
//****************************************************************************************////////    
//------------------ START Unit Seclection in booking mode Daily Booking:-----------------------
//******************************************************************************************//////  
                if ($category->field_agres_unitselectionmethod[$langcode_caus][0]['value'] == '2') {

                    if (!isset($_SESSION['availableunittypes']) || !isset($_SESSION['agreservationuserrequest'])) {
                        drupal_goto();
                    }
                    $availableunittypes = $_SESSION['availableunittypes'];
                    $userrequest = $_SESSION['agreservationuserrequest']; //unserialize($suserrequest);//
//      $productarray = array();
//    //////////////////////////////////////////////////////////////////////
                    $resnodes = agreservations_get_reservable_items('agreservations_unit', $userrequest['checkintime'], $userrequest['checkouttime'], $category->nid);
                    $availableunittypes = _agreservations_get_reservable_unittypes($resnodes, FALSE);
/////////////////////////////////////////////////////////////////////////////
                    // Get current language code
                    global $language;
                    $current_lang = $language->language;
//                drupal_set_message('<pre>$availableunittypes$availableunittypes'.$current_lang.'--'.print_r($availableunittypes,true).'</pre>');
                    $productarray = array();
                    foreach ($availableunittypes as $availableunittype) {
                        //get according products:
                        $data = array('checkintime' => $userrequest['checkintime'],
                            'checkouttime' => $userrequest['checkouttime'],
                            'bookingmode' => $category->field_agres_bookingmode[$langbm][0]['value'],
                            'module' => 'agres_categories');

                        $price = agres_bookings_calculate_price($availableunittype['rtnode']->nid, $data);
                        $productarray[] = $availableunittype['rtnode']->nid;
                    }
                    $_SESSION['agres_bookings_productsavailable'] = $productarray;
                    $bookableproducts = '';
                    $bookableproducts .= '<a class="Button" href="' . base_path() . '"><span class="btn">' . '&nbsp&nbsp' . t('back') . '&nbsp&nbsp' . '</span></a><br>';
                    $items = uc_cart_get_contents(uc_cart_get_id());
                    if (count($items) == 0) {
                        $bookableproducts .= '<div><b>' . t('Booking From %checkin to %checkout', array('%checkin' => $userrequest['checkintime'], '%checkout' => $userrequest['checkouttime'])) . '</b></div>';
                    } else {
                        $cartinfoform = drupal_get_form('agres_bookings_cart_info_form');
                        $bookableproducts .= drupal_render($cartinfoform);
                        $cartviewform = drupal_get_form('uc_cart_view_form', $items); // drupal_get_form('agres_bookings_cart_view_form', $items);
//                    $cartviewform = drupal_get_form('agres_bookings_cart_view_form', $items);
                        $bookableproducts .='<div id="ajxagrcartview">';
                        $bookableproducts .= drupal_render($cartviewform);
                        $bookableproducts .='</div>';
                        $bookableproducts .= '<div><h3>' . t('Choose items:') . '</h3></div>';
                    }
                    $build = array();
                    if ($agrproductresult = views_get_view('agres_uc_catalog')) {
                        // Force the breadcrumb path to this page.
                        $agrproductresult->override_path = 'catalog';
                        $agrproductresult->args = array($category->field_agres_bookingmode[$langbm][0]['value'], $userrequest['checkintime'], $userrequest['checkouttime']);
                        $build['products'] = array(
                            '#markup' => $agrproductresult->execute_display('agres_uc_catalog', array($category->field_agres_bookingmode[$langbm][0]['value'], $userrequest['checkintime'], $userrequest['checkouttime'])),
                        );
                    }
                    $bookableproducts .= drupal_render($build['products']);
                    $bookableproducts .= '<br><a class="Button" href="' . base_path() . '"><span class="btn">' . '&nbsp&nbsp' . t('back') . '&nbsp&nbsp' . '</span></a>';
                    return $bookableproducts;
                } else {
                    return drupal_get_form('_agres_categories_form_standard', $category);
                }
            }
        } else {
            return array();
        }
    }

}
