#!/usr/local/bin/perl
use Data::Dumper;
use Test::More;
use strict;
use warnings;

sub p { print Dumper @_; }

sub qsort {
  my ($array_ref) = @_;

  if (@$array_ref <= 1) {
    return $array_ref;
  }

  my $pivot = $array_ref->[0];

  shift @$array_ref;
  my ($lesser, $greater) = partition($array_ref, $pivot);

  [@{&qsort($lesser)}, $pivot, @{&qsort($greater)}];
}

sub partition {
  my ($array_ref, $pivot) = @_;
  my $lesser = [];
  my $greater = [];

  foreach my $item (@$array_ref) {
    if ($item >= $pivot) {
      push @$greater, $item;
    } else {
      push @$lesser, $item;
    }
  }

  ($lesser, $greater);
}

# Test

subtest 'partition' => sub {
  is_deeply [partition([1,2,3,4,5], 3)], [[1,2], [3,4,5]];
};

subtest 'qsort' => sub {
  is_deeply qsort([4,1,3,2]), [1,2,3,4];
  is_deeply qsort([1,1,1,1]), [1,1,1,1];
};

done_testing();
