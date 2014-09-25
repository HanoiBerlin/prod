<?php

/**
 * @file
 * Template for invoiced orders.

<div class="invoice-invoiced">
  <div class="header">
    <img src="<?php print $content['invoice_logo']['#value']; ?>"/>
    <div class="invoice-header">
        <p><?php print render($content['invoice_header']); ?></p>
    </div>
  </div>

  <hr/>

  <div class="invoice-header-date"><?php print render($content['invoice_header_date']); ?></div>
  <div class="customer"><?php print render($content['commerce_customer_billing']); ?></div>
  <div class="invoice-number"><?php print render($content['order_number']); ?></div>
  <div class="order-id"><?php print render($content['order_id']); ?></div>

  <div class="line-items">
    <div class="line-items-view"><?php print render($content['commerce_line_items']); ?></div>
    <div class="order-total"><?php print render($content['commerce_order_total']); ?></div>
  </div>
  <div class="invoice-text"><?php print render($content['invoice_text']); ?></div>

  <div class="invoice-footer"><?php print render($content['invoice_footer']); ?></div>
</div>






 */

?>




<?php




/** 

print_r(get_defined_vars());
 * @file
 * Template for invoiced orders.
 */

?>

<div class="invoice-invoiced">
  <div class="header">
    <img src="<?php print $content['invoice_logo']['#value']; ?>"/>

	<div class ="invoice-title">
	Gundara<br>
	</div>

	<div class ="invoice-site">
	<?php print t('http://gundara.com'); ?><br>
	</div>

	<div class="invoice-header">
        <?php print render($content['invoice_header']); ?>  
	</div>
  </div>


  <div class="invoice-header-date"><br><?php print render($content['invoice_header_date']); ?>
	<b><i><?php print '<br>- ' . render($content['order_number']) . ' -'; ?></b></i>
  </div>

	
  <div class="customer"><b><?php print t('Billing Info:'); ?></b><br /><?php print render($content['commerce_customer_billing']); ?></div>

  <div class="customer_shipping"><br><b><?php print t('Shipping Address:'); ?></b><br /><?php print render($content['commerce_customer_shipping']); ?></div>



  <div class="line-items">
    <div class="line-items-view"><?php print render($content['commerce_line_items']); ?></div>
    <div class="order-total"><?php print render($content['commerce_order_total']); ?></div>
  </div>

  <div class="invoice-text"><?php print render($content['invoice_text']); ?></div>

  <div class="invoice-footer"><b>-    <?php print t('Thank you for being our client and for paying this bill within 15 days following the order date'); ?>    -</b></i><br><br><?php print render($content['invoice_footer']); ?>


<b><?php print t('Bank Details'); ?>: </b>Volksbank Göttingen / Gunda Wiegmann / <i><?php print t('Bank Ref.'); ?></i>: 26090050  / <i><?php print t('Account Number'); ?></i>: 0104857001 / 
<i>BIC</i>: GENODEF1GOE / <br><i>IBAN</i>: DE64260900500104857001 / <i><?php print t('Bank Address'); ?> </i>: Volksbank Göttingen eG / Kurze-Geismar-Straße 2 / 37073 Göttingen / <?php print t('Germany'); ?> <br>
		<b>Paypal:</b>gundara@gundara.com<br></div>


</div>
