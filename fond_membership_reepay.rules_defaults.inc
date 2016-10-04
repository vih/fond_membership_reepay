<?php
/**
 * @file
 * fond_membership_reepay1.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function fond_membership_reepay_default_rules_configuration() {
    $items = array();
    $items['rules_create_reepay_subscription'] = entity_import('rules_config', '{ "rules_create_reepay_subscription" : {
      "LABEL" : "Create Reepay Subscription",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "8",
      "OWNER" : "rules",
      "TAGS" : [ "Fond" ],
      "REQUIRES" : [ "commerce_order", "fond_membership_reepay", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "commerce_order" ],
            "product_type" : { "value" : { "membership" : "membership" } },
            "operator" : "\\u003E=",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "fond_membership_reepay_action_create_reepay_subscription" : { "order" : [ "commerce-order" ] } },
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "completed" } }
      ]
    }
  }');
    return $items;
}
