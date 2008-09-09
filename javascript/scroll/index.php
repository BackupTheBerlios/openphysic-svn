<html>

<head>
<title>Scroll</title>

<script language="JavaScript">
var direction = true; // true=bas false=haut
var scroll = true;

function pageScroll() {
  scrolldelay = setTimeout('pageScroll()',100); // scrolls every 1000 milliseconds
  if (scroll) {
    if (bottom())
      direction=false;

    if (top())
      direction=true;

    if (direction) {
      window.scrollBy(0,10);
    } else {
      window.scrollBy(0,-10);    
    }
  }
}

function bottom()
{
  if ((document.body.scrollTop + document.body.clientHeight) == document.body.scrollHeight) {
    return true;
  } else {
    return false;
  }
}

function top()
{
  if ( document.body.scrollTop==0 ) {
    return true;
  } else {
    return false;
  }
}

</script>

</head>


<body onLoad="pageScroll()">
<h1>Scroll</h1>
<?php
$str="Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Nulla metus velit, lobortis a, tincidunt vitae, bibendum tincidunt, eros. In eget orci aliquam eros tristique feugiat. Vestibulum feugiat vehicula enim. Aenean bibendum ipsum in enim. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec pharetra mi non odio. Integer orci nisl, placerat non, adipiscing et, congue non, velit. Integer ipsum. Duis ac ipsum at eros egestas aliquam. Praesent quis sem et justo rutrum tincidunt. Morbi mattis pretium urna. Pellentesque eget orci auctor libero tristique condimentum. ";
for ($i==0 ; $i<7 ; $i++) {
  echo $str;
}
echo "\n";
?>
</body>

</html>
