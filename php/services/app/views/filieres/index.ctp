<div class="filieres index">
<h2><?php __('Filieres');?></h2>
<p>
<?php
echo $paginator->counter(array(
'format' => __('Page %page% of %pages%, showing %current% records out of %count% total, starting on record %start%, ending on %end%', true)
));
?></p>
<table cellpadding="0" cellspacing="0">
<tr>
	<th><?php echo $paginator->sort('id');?></th>
	<th><?php echo $paginator->sort('name');?></th>
	<th><?php echo $paginator->sort('nb_gr_td');?></th>
	<th><?php echo $paginator->sort('nb_gr_tp');?></th>
	<th class="actions"><?php __('Actions');?></th>
</tr>
<?php
$i = 0;
foreach ($filieres as $filiere):
	$class = null;
	if ($i++ % 2 == 0) {
		$class = ' class="altrow"';
	}
?>
	<tr<?php echo $class;?>>
		<td>
			<?php echo $filiere['Filiere']['id']; ?>
		</td>
		<td>
			<?php echo $html->link($filiere['Filiere']['name'], array('action'=>'view', $filiere['Filiere']['id'])); ?>
		</td>
		<td>
			<?php echo $filiere['Filiere']['nb_gr_td']; ?>
		</td>
		<td>
			<?php echo $filiere['Filiere']['nb_gr_tp']; ?>
		</td>
		<td class="actions">
			<?php echo $html->link(__('View', true), array('action'=>'view', $filiere['Filiere']['id'])); ?>
			<?php echo $html->link(__('Edit', true), array('action'=>'edit', $filiere['Filiere']['id'])); ?>
			<?php echo $html->link(__('Delete', true), array('action'=>'delete', $filiere['Filiere']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $filiere['Filiere']['id'])); ?>
		</td>
	</tr>
<?php endforeach; ?>
</table>
</div>
<div class="paging">
	<?php echo $paginator->prev('<< '.__('previous', true), array(), null, array('class'=>'disabled'));?>
 | 	<?php echo $paginator->numbers();?>
	<?php echo $paginator->next(__('next', true).' >>', array(), null, array('class'=>'disabled'));?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Nouvelle Filiere', true), array('action'=>'add')); ?></li>
		<li><?php echo $html->link(__('Lister Matieres', true), array('controller'=> 'matieres', 'action'=>'index')); ?> </li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Bilan des besoins par filière', true), array('controller'=> 'vue_filieres_total_besoins', 'action'=>'index')); ?> </li>	
	</ul>
</div>
