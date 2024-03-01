<?php
$company_component = 1.787;

$bonus = isset($_POST['bonus']) ? floatval($_POST['bonus']) : 0;
$ratingValue = isset($_POST['rating']) ? intval($_POST['rating']) : 0;

$multiplier = [
    1 => [0.0, 0.29],
    2 => [0.30, 0.80],
    3 => [0.80, 1.05],
    4 => [1.06, 1.20],
    5 => [1.21, 1.60]
];

$minBonus = $company_component * 0.445 * $bonus + $multiplier[$ratingValue][0] * $bonus * 0.555;
$maxBonus = $company_component * 0.445 * $bonus + $multiplier[$ratingValue][1] * $bonus * 0.555;

echo "Bonus Range: [" . number_format($minBonus, 2) . " , " . number_format($maxBonus, 2) . "]";
?>
