<?php
/**
 * Implementation of hook_rules_action_info().
 */
function fond_membership_reepay_rules_action_info() {
    return array(
        'fond_membership_reepay_action_create_reepay_subscription' => array(
            'label' => t('Create Reepay subscription from order object'),
            'parameter' => array(
                'order' => array(
                    'type' => 'commerce_order',
                    'label' => t('Order'),
                )
            ),
            'configurable' => FALSE,
            'group' => t('Fond'),
            'callbacks' => array(
                'execute' => 'fond_membership_reepay_action_create_reepay_subscription',
            ),
        ),
    );
}

/**
 * Create Reepay subscription
 *
 * @param object $order
 *
 * @return string
 */
function fond_membership_reepay_action_create_reepay_subscription($order) {
    return fond_membership_reepay_create_invoice($order);
}
