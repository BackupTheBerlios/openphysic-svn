/*
Gestion du scrolling vertical d'une page HTML ou d'un iframe
Défile vers le bas.
Quand le bas est atteint défile vers le haut
Quand le haut est atteint, défile vers le bas
etc...
*/

var direction = true; // true=bas false=haut
var scroll = true;

var delay=100;
var step=5;

var obj=null;

function pageScroll(new_obj) {
  scrolldelay = setTimeout('pageScroll(obj)', delay); // scrolls every xxx milliseconds

  obj=new_obj;
  //obj=document.body;
  //obj=document.getElementById('mydata').src;

  //alert('objet autoscroll "'+obj.value+"'")

  if (scroll) {
    if ( bottom() ) {
      direction=false;
      //alert("bottom");
    }

    if ( top() ) {
      direction=true;
      //alert("top");
    }

    if ( direction ) {
      window.scrollBy(0, step);
    } else {
      window.scrollBy(0, -step);    
    }
  }
}

function bottom()
{
  if ( (obj.scrollTop + obj.clientHeight) == obj.scrollHeight ) {
    return true;
  } else {
    return false;
  }
}

function top()
{
  if ( obj.scrollTop==0 ) {
    return true;
  } else {
    return false;
  }
}

