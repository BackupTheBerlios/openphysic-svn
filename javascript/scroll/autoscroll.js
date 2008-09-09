var direction = true; // true=bas false=haut
var scroll = true;

var delay=100;
var step=5;

var obj=null;

function pageScroll(new_obj) {
  scrolldelay = setTimeout('pageScroll(obj)', delay); // scrolls every xxx milliseconds

  obj=new_obj;

  if (scroll) {
    if ( bottom() )
      direction=false;

    if ( top() )
      direction=true;

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

