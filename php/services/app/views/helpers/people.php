<?php
class PeopleHelper extends AppHelper {
	function format($perso) {
		return sprintf("(%s) %s %s", $perso [ 'initiales' ], $perso [ 'nom' ], $perso [ 'prenom' ]);
		//return "({$perso [ 'initiales' ]}) {$perso [ 'nom' ]} {$perso [ 'prenom' ]}";
	}
}
?>