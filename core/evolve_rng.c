// Copyright 2011-2015 Ewerton Assis
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "evolve_rng.h"

static int is_rng_set = 0;
static const gsl_rng_type *T;

void
evolve_set_rng (unsigned long int seed)
{
  if (is_rng_set)
    return;
  gsl_rng_env_setup ();
  T = gsl_rng_default;
  rng = gsl_rng_alloc (T);
  gsl_rng_set (rng, seed);
  is_rng_set = 1;
}

void
evolve_tear_rng ()
{
  gsl_rng_free (rng);
  is_rng_set = 0;
}
