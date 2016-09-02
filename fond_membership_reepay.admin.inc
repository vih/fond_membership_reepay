<?php

/**
 * @file
 */

/**
 * Return the Billy global settings form.
 */
function fond_membership_reepay_admin_settings() {
    $form['fond_membership_reepay_api_key'] = array(
        '#type' => 'textfield',
        '#title' => t('Reepay API Key'),
        '#required' => TRUE,
        '#default_value' => variable_get('fond_membership_reepay_api_key', ''),
        '#description' => t('The API key for your Reepay account. Get or generate a valid API key at Reepay. Please read the !termslink.', array('!termslink' => l(t('Reepay API Terms'), 'https://api.reepay.com/api'))),
    );

    // Initiate API Client.
    try {
        $api_request = fond_membership_reepay_get_api_client();
    }
    catch (Exception $e) {
        drupal_set_message($e->getMessage(), 'error');
        return system_settings_form($form);
    }

    return system_settings_form($form);
}
