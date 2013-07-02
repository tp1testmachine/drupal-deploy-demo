Drupal deployment - CI - testing demo
-------------------------------------

How to use this repo:

* 1. Fork this repo
* 2. Create a local dev copy: 

    git pull origin master

* 3. Create a database

    echo 'create database devdb' | mysql -uroot -proot

* 4. Set up Drupal

    drush si --db-url="mysql://root:root@localhost/devdb" --account-name="root" --account-pass="root" -y

* 5. Enable the deployment module. There should be only one module to enable which will completely deploy your site (except content).

    drush en mysite_deploy

* 6. Use devel generate to generate some fake content

    drush en devel_generate
    drush generate-content 50

* 7. Set up an integration server with Jenkins, which will deploy the site and test it. You can set up Jenkins to monitor the master branch, and perform the following tasks (the database must already exist on the Jenkins server) (Note that the base_url must be set in Jenkins's settings.php file for this to work):

    drush si --db-url="mysql://root:root@localhost/jenkinsdb" --account-name="root" --account-pass="root" -y
    drush en mysite_deploy simpletest
    drush test-run "mysite deploy""

* 8. Set up your Jenkins server to push to git on the integration and master branches

* 9. At this point, you have a system where:

 * Developers always pull from master and push to master
 * Jenkins pushes to the integration branch only when all the tests pass

* 10. Do any or all of the following tasks (and add tests for them while you are at it!), and try deploying them to the forked repo in the master branch, and have jenkins push them to the integration branch. You can then have a relatively stable environment which tracks the integration branch.

 * Disable the toolbar and enable admin_toolbar instead
 * Create a view with only one latest image on the front page
 * Change the image style to display in the view
 * Display a large image (instead of the original image) on the node view page.
 * etc...
