<?php
/**
 * @file
 * shipping.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function shipping_default_rules_configuration() {
  $items = array();
  $items['commerce_shipping_service_freie_lieferung'] = entity_import('rules_config', '{ "commerce_shipping_service_freie_lieferung" : {
      "LABEL" : "Rate Freie Lieferung",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "inline_conditions", "commerce_shipping" ],
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "Order" } },
      "IF" : [
        { "commerce_order_compare_order_amount" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003E",
            "total" : { "value" : { "amount" : 2000, "currency_code" : "EUR" } }
          }
        }
      ],
      "DO" : [
        { "commerce_shipping_service_rate_order" : {
            "shipping_service_name" : "freie_lieferung",
            "commerce_order" : [ "commerce-order" ]
          }
        }
      ]
    }
  }');
  $items['commerce_shipping_service_lieferung'] = entity_import('rules_config', '{ "commerce_shipping_service_lieferung" : {
      "LABEL" : "Rate Lieferung",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order", "commerce_shipping" ],
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "Order" } },
      "IF" : [
        { "commerce_order_compare_address" : {
            "commerce_order" : [ "commerce_order" ],
            "address_field" : "commerce_customer_shipping|commerce_customer_address",
            "address_component" : "postal_code",
            "value" : "12435"
          }
        }
      ],
      "DO" : [
        { "commerce_shipping_service_rate_order" : {
            "shipping_service_name" : "lieferung",
            "commerce_order" : [ "commerce-order" ]
          }
        }
      ]
    }
  }');
  return $items;
}
