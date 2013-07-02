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

* 5. Enable the deployment module

    drush en mysite_deploy

    