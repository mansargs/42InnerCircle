# Inception

> A Docker-based web infrastructure project from the 42 curriculum.

## Overview

Inception sets up a secure, multi-container web stack using Docker Compose.
The stack includes:
- `nginx` as the HTTPS reverse proxy
- `wordpress` as the PHP application
- `mariadb` as the database server

The project uses:
- Docker Compose for orchestration
- Named volumes with host bind mounts for persistence
- Docker secrets for sensitive credentials
- A custom Docker bridge network for service communication

## Repository structure

- `Makefile` — build, run, and cleanup targets
- `srcs/docker-compose.yml` — service definitions and volumes
- `srcs/.env_example` — example environment variables
- `srcs/secrets/` — secret files for passwords
- `srcs/requirements/nginx/` — NGINX image build files
- `srcs/requirements/wordpress/` — WordPress image build files
- `srcs/requirements/mariadb/` — MariaDB image build files

## Prerequisites

- Docker installed
- Docker Compose available
- `make` installed
- Linux environment (project requirement)
- `openssl` installed if you create your own certificates

## Setup

1. Copy the sample environment file:

```bash
cp srcs/.env_example srcs/.env
```

2. Edit `srcs/.env` with your values:

```bash
nano srcs/.env
```

Minimum required values:

```bash
USERNAME=your_login
DOMAIN_NAME=your_login.42.fr
CERTS=/etc/nginx/ssl/your_login.crt
KEYOUT=/etc/nginx/ssl/your_login.key
MYSQL_USER=wordpress
MYSQL_DATABASE=wordpress
MYSQL_HOSTNAME=mariadb
WORDPRESS_TITLE="My Website"
WORDPRESS_ROOT_USERNAME=wpadmin
WORDPRESS_ROOT_EMAIL=admin@example.com
WORDPRESS_USER_USERNAME=subscriber
WORDPRESS_USER_EMAIL=user@example.com
```

3. Create the secret files:

```bash
mkdir -p srcs/secrets/maria_db srcs/secrets/wordpress

echo -n "your_db_password" > srcs/secrets/maria_db/db_password.txt
echo -n "your_root_password" > srcs/secrets/maria_db/db_root_password.txt
echo -n "your_wp_user_pass" > srcs/secrets/wordpress/wp_user_password.txt
echo -n "your_wp_admin_pass" > srcs/secrets/wordpress/wp_root_password.txt
```

4. Add your domain to `/etc/hosts`:

```bash
sudo nano /etc/hosts
```

Add a line like:

```text
127.0.0.1 your_login.42.fr
```

## Run the project

Start everything with:

```bash
make
```

This target will:
- verify that `srcs/.env` exists
- create the host data directories under `/home/$USER/data`
- verify required secret files exist
- build and start the containers

Access the site at the domain configured in `srcs/.env`:

```text
https://your_login.42.fr
```

## Useful commands

```bash
make down         # stop containers
make clean        # stop containers and remove named volumes + host data directories
make fclean       # full cleanup: stop containers, remove volumes, images, secrets, and build cache
make start        # start stopped containers
make stop         # stop running containers
```

Inspect containers and logs directly:

```bash
docker ps

docker-compose -f srcs/docker-compose.yml logs -f nginx
docker-compose -f srcs/docker-compose.yml logs -f wordpress
docker-compose -f srcs/docker-compose.yml logs -f mariadb
```

## Service details

- `nginx`: exposes port `443` and forwards requests to WordPress
- `wordpress`: connects to `mariadb` and serves the WordPress application
- `mariadb`: stores WordPress data and uses Docker secrets for passwords

## Persistence and networking

- `wordpress-volume` stores WordPress files on the host at `/home/$USER/data/wordpress`
- `mariadb-volume` stores database files on the host at `/home/$USER/data/mariadb`
- Services communicate over the custom bridge network `inception`
- Secrets are loaded from `srcs/secrets/` and referenced in `srcs/docker-compose.yml`

## Notes

- Only HTTPS is exposed, so use `https://` in your browser
- The `DOMAIN_NAME` from `srcs/.env` must match the host entry in `/etc/hosts`
- If the `make` output still says `https://mansargs.42.fr`, update `DOMAIN_NAME` in `srcs/.env`
- Do not commit `srcs/.env` or anything under `srcs/secrets/`

## References

- Docker: https://docs.docker.com/
- Docker Compose: https://docs.docker.com/compose/
- NGINX docs: https://nginx.org/en/docs/
- WordPress docs: https://wordpress.org/support/
- MariaDB docs: https://mariadb.com/docs/
