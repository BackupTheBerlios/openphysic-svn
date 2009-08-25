<div class="users view">
<h2><?php  __('Utilisateur');?></h2>
	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $user['User']['id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __("Nom d'utilisateur"); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $user['User']['username']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Mot de passe'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $password->hide($user['User']['password']); ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Groupe'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $html->link($user['Group']['name'], array('controller'=> 'groups', 'action'=>'view', $user['Group']['id'])); ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Créé'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $user['User']['created']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Modifié'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $user['User']['modified']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Perso Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $user['User']['perso_id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Role'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $user['User']['role']; ?>
			&nbsp;
		</dd>
	</dl>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Modifier le mot de passe', true), array('action'=>'change_password', $user['User']['id'])); ?> </li>
		<li><?php echo $html->link(__('Editer cet utilisateur', true), array('action'=>'edit', $user['User']['id'])); ?> </li>
		<li><?php echo $html->link(__('Lister les utilisateurs', true), array('action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouvel utilisateur', true), array('action'=>'add')); ?> </li>
		<li><?php echo $html->link(__('Supprimer cet utilisateur', true), array('action'=>'delete', $user['User']['id']), null, sprintf(__('Êtes-vous sûr de vouloir supprimer l\'utilisateur # %s ?', true), $user['User']['id'])); ?> </li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister les groupes d\'utilisateurs', true), array('controller'=> 'groups', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouveau groupe d\'utilisateurs', true), array('controller'=> 'groups', 'action'=>'add')); ?> </li>
	</ul>
</div>
